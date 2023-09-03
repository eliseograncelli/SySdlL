#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct paths {
    char ruta[128];
    int niveles;
};

char * cargaRuta (void);     // NO PROGRAMAR
int validaRuta (char *);    // PROGRAMAR
char * guardaRuta (char *, struct paths *, int *);  // PROGRAMAR
int * nivelesRuta (char *);   // NO PROGRAMAR

main() {
    int i, validado, cant_paths = 0;
    char * path, continua, * guardado;
    struct paths p_paths[100];
    do {
        system("cls");
        fflush(stdin);
        path = cargaRuta();
        printf("\n\nRuta cargada: %s",path);
        validado = validaRuta(path);
        if (validado==0) {
            printf("\n\nSintaxis Correcta\n\n");
            system("pause");
            guardado = guardaRuta(path, p_paths, &cant_paths) ;
            printf("\n\n%s\n\n",guardado);
        } else {
            printf("\n\nSintaxis Incorrecta\n\n");
        }
        system("pause");
        printf("\n\nLISTADO DE PATHS\n");
        printf("----------------\n");
        for (i=0;i<=cant_paths-1;i++) {
            printf("%s | %d niveles\n",p_paths[i].ruta,p_paths[i].niveles);
        }
        printf("\n\nContinua (s/n) ");
        fflush(stdin);
        scanf("%c",&continua);
    } while (continua=='s' || continua=='S');
}


char * cargaRuta(void) {    // NO PROGRAMAR
static char p_ruta[128];
int i=0;
printf("\nIngrese el path: ");
while ((p_ruta[i] = getchar()) != EOF){ i++; }
p_ruta[--i] = '\0';
return(p_ruta);
}


int validaRuta(char * path) {
int i=1,j=0;
if ( strlen(path)<3 || strlen(path)>128 ) {return 1;}
if ( strlen(path)>=3 && strlen(path)<=128 && ( path[0]!='/' || path[strlen(path)-1]!='/' ) ) {return 1;}
while (i<strlen(path)) {
   while (path[i]!='/') {
        if ( isalnum(path[i]) ) { j++; i++; }
        else { return 1; }
   }
   if (j>=1 && j<=8) { j=0; i++; }
   else { return 1; }
}
return 0;
}


char * guardaRuta(char * path, struct paths * p_paths, int * cant_paths) {
int i, * nivel;
static char mensaje[25];
strcpy(mensaje,"Path creado con exito");
for (i=0;i<*cant_paths;i++) {
        if (strcmp(p_paths[i].ruta,path) == 0) {
                strcpy(mensaje,"El path ya existe");
                break;
        }
}
if (strcmp(mensaje,"Path creado con exito") == 0) {
            nivel = nivelesRuta(path);
            strcpy(p_paths[*cant_paths].ruta,path);
            p_paths[*cant_paths].niveles = nivel;    // *nivel;
            (*cant_paths)++;
}
return mensaje;
}


int * nivelesRuta(char * path) {  // NO PROGRAMAR
static int nivel;
int i;
nivel=0;
i=1;
while (path[i]!='\0') {
        if (path[i] == '/') { nivel++; }
        i++;
}
return nivel;    // &nivel;
}
