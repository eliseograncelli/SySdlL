#include <stdio.h>
#include <string.h>

struct palabras {
    char pal[20];
    int pos;
};

char * carga (int *);     // PROGRAMAR
struct palabras * separa (char *, int, int *);    // NO PROGRAMAR
int diccionario (char [500][20]);   // NO PROGRAMAR
struct palabras * corrector (struct palabras *, int, char dic[][20], int);  // PROGRAMAR

main() {
    int i, car=0, cant_pal=0, cant_dic, cant_inv=0;
    char * texto;
    char dic [500][20];
    struct palabras * p_separa;
    struct palabras * p_inv;

    texto = carga(&car);
    printf("\n\nTexto cargado: %s",texto);

    p_separa = separa(texto, car, &cant_pal);
    printf("\n\n\nCantidad de palabras separadas: %d\n\n",cant_pal);
    printf("Palabra\t\tPosicion\n");
    printf("------------------------\n");
    for (i=0;i<cant_pal;i++){
        printf("%s\t\t%d\n",p_separa[i].pal,p_separa[i].pos);
        //p_pal++;
    }
    system("pause");

    cant_dic = diccionario (dic); //invoco al diccionario para cargarlo en memoria

    p_inv = corrector(p_separa, cant_pal, dic, cant_dic);
    printf("\n\n\nPalabras Incorrectas\n");
    printf("Palabra\t\tPosicion\n");
    printf("------------------------\n");
    for (i=0;strcmp(p_inv[i].pal,"*****")!=0;i++){
        printf("%s\t\t%d\n",p_inv[i].pal,p_inv[i].pos);
        //p_pal++;
    }
    system("pause");

}


char * carga(int * car) {
static char p_texto[1000];
printf("\n\nIngrese la noticia: \n");
while ((p_texto[*car] = getchar()) != EOF && *car<999){ (*car)++; }
p_texto[(*car)--] = '\0';
return(p_texto);
}


struct palabras * separa(char * texto, int car, int * cant_pal) {
static struct palabras p_palabras[500];
int i,j=0,cantaux=0;

for (i=0;i<car;i++) {
    if (texto[i]!=' ' && texto[i]!=',' && texto[i]!=';' && texto[i]!='.' && texto[i]!=':' && texto[i]!='\n') {
        p_palabras[cantaux].pal[j] = texto[i];
        j++;
    }
    else {
        if (texto[i+1]!=' ' && texto[i+1]!=',' && texto[i+1]!=';' && texto[i+1]!='.' && texto[i+1]!=':' && texto[i+1]!='\n') {
            cantaux++;
            j=0;
        }
    }
}

for (i=0;i<=cantaux;i++) {
   p_palabras[i].pos = i+1;
}

*cant_pal = cantaux + 1 ;
return p_palabras;
}


int diccionario(char dic[500][20]) { //No programar, hago la funcion para cargar algunas palabras en el dic
char opc;
int i=0;
do {
    system("cls");
    printf("\nIngrese la palabra nro. %i: ",i+1);
    scanf("%s",dic[i]);
    printf("\nContinua (s/n) ");
    opc = getche();
    i++;
} while (opc!='n');
return i;
}


struct palabras * corrector(struct palabras * p_separa, int cant_pal, char dic[500][20], int cant_dic) {
int i=0,j,k;
char existe;
static struct palabras p_pal_inv[500];
for (j=0;j<cant_pal;j++) {
        existe = 'N';
        for(k=0;k<cant_dic;k++) {
            if (strcmp(p_separa->pal,dic[k]) == 0) {
                    existe='S';
                    break;
            }
        }
        if (existe == 'N') {
            strcpy(p_pal_inv[i].pal,p_separa->pal);
            p_pal_inv[i].pos = p_separa->pos;
            i++;
        }
        p_separa++;
}
strcpy(p_pal_inv[i].pal,"*****");
return p_pal_inv;
}
