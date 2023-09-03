#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct pal {
    char cadena[25];
    char tipo[20];
};

int carga_reserva (char [40][15]);   // PROGRAMAR
char * carga_texto (void);            // PROGRAMAR
struct pal * separa (char *, int *);  // NO PROGRAMAR
struct pal * depura (struct pal *,  int) ;  // NO PROGRAMAR
void clasifica (struct pal *, char pal_res[][15], int) ; // PROGRAMAR

main() {
    int i, cant_res, cant_pal=0;
    char pal_res[40][15];
    char * texto;
    struct pal * p_pal_todas;
    struct pal * p_pal_dep;

    cant_res = carga_reserva(pal_res);
    printf("\n\nCantidad de palabras reservadas cargadas: %d\n",cant_res);
    for (i=0;i<cant_res;i++) {
            printf("%s ",pal_res[i]);
    }

    texto = carga_texto();
    printf("\n\nTexto cargado: %s",texto);

    p_pal_todas = separa(texto, &cant_pal);
    printf("\n\n\nCantidad de palabras separadas: %d\n\n",cant_pal);
    printf("Cadena\t\tTipo\n");
    printf("--------------------\n");
    for (i=0;i<cant_pal;i++){
        printf("%s\t\t%s\n",p_pal_todas[i].cadena,p_pal_todas[i].tipo);
        //p_pal_todas++;
    }
    system("pause");

    p_pal_dep = depura(p_pal_todas, cant_pal);
    printf("\n\n\nPalabras Depuradas\n");
    printf("Cadena\t\tTipo\n");
    printf("--------------------\n");
    for (i=0;strcmp(p_pal_dep[i].cadena,"*****")!=0;i++){
        printf("%s\t\t%s\n",p_pal_dep[i].cadena,p_pal_dep[i].tipo);
        //p_pal_dep++;
    }
    system("pause");

    clasifica(p_pal_dep, pal_res, cant_res);
    printf("\n\n\nPalabras Clasificadas\n");
    printf("Cadena\t\tTipo\n");
    printf("--------------------\n");
    for (i=0 ; strcmp(p_pal_dep->cadena,"*****")!=0 ; i++){
        printf("%s\t\t%s\n",p_pal_dep->cadena,p_pal_dep->tipo);
        p_pal_dep++;
    }
    system("pause");

}


int carga_reserva(char pal_res[40][15]) {
char opc;
int i=0;
do {
    system("cls");
    printf("\nIngrese la palabra reservada nro. %i: ",i+1);
    scanf("%s",pal_res[i]);
    printf("\nContinua (s/n) ");
    opc = getche();
    i++;
} while (opc!='n');
return i;
}


char * carga_texto() {
static char p_texto[1000];
int i=0;
printf("\n\nIngrese el texto: \n");
while ( (p_texto[i] = getchar()) != EOF && i<999 ) i++;
p_texto[i] = '\0';
return(p_texto);
}


struct pal * separa(char * texto, int * cant_pal) {
static struct pal p_palabras[500];
char * ptr;
char s2[] = "' ' , '.' , ',' , ';' , ':' , '\n'";
ptr=strtok(texto,s2); //busco la primera palabra, que va a estar separada por espacio coma  punto dos puntos <enter>.
//printf("\n%s\n",ptr); //la muestro
strcpy(p_palabras[*cant_pal].cadena,ptr);  //y la guardo
(*cant_pal)++;
while (ptr != NULL) {
    ptr=strtok(NULL,s2); //guardo en el puntero ptr la direccion en la que comienza la palabra
    if (ptr!=NULL) {
        //printf("%s\n",ptr); //muestro la palabra
        strcpy(p_palabras[*cant_pal].cadena,ptr);  //guardo un puntero que apunte al comienzo de la palabra
        (*cant_pal)++;
    }
}
return p_palabras;
}


struct pal * depura(struct pal * p_pal_todas, int cant_pal) {
int i=0,j,k;
char existe;
static struct pal p_palabras_dep[500];
for (j=0;j<cant_pal;j++) {
        existe = 'N';
        for(k=0;k<i;k++) {
            if (strcmp(p_pal_todas->cadena,p_palabras_dep[k].cadena) == 0) {
                    existe='S';
                    break;
            }
        }
        if (existe == 'N') {
            strcpy(p_palabras_dep[i].cadena,p_pal_todas->cadena);
            i++;
        }
        p_pal_todas++;
}
strcpy(p_palabras_dep[i].cadena,"*****");
return p_palabras_dep;
}



void clasifica(struct pal * p_pal_dep, char pal_res[40][15], int cant_res) {
int i,k;
char identificador;
for (i=0;strcmp(p_pal_dep->cadena,"*****")!=0;i++) {
    //asigno por defecto el tipo "Otra"
    strcpy(p_pal_dep->tipo,"Otra");

    // Palabra Reservada
    for(k=0;k<cant_res;k++) {
        if (strcmp(p_pal_dep->cadena,pal_res[k]) == 0) {
            strcpy(p_pal_dep->tipo,"Palabra Reservada");
        }
    }

    // Identificador
    if(strcmp(p_pal_dep->tipo,"Palabra Reservada")!=0 && strlen(p_pal_dep->cadena)<=8 && isalpha(p_pal_dep->cadena[0])!=0) {
        identificador = 'S';
        for(k=1;k<strlen(p_pal_dep->cadena);k++) {
                    if (isalnum(p_pal_dep->cadena[k])==0 && p_pal_dep->cadena[k]!='_') {
                            identificador = 'N';
                            break;
                    }
        }
        if (identificador == 'S') strcpy(p_pal_dep->tipo,"Identificador");
    }
p_pal_dep++;
}
}

