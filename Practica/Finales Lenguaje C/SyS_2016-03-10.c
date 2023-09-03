#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct tab
{ char cadena[25];
  int  alfa; // la cantidad de caracteres alfabéticos de cadena
} ;

char * Ingresa_Cadena();   //NO PROGRAMAR
struct tab * Forma_Tabla (char *, int * filas);  //PROGRAMAR
void Busca_Muestra (int longi, struct tab *, int filas);  //PROGRAMAR

main() {
int longi, filas=0;
char * cadena;
struct tab * p_tabla;
char rta = 's';
do {
    system("cls");
    cadena = Ingresa_Cadena();
    fflush(stdin);
    p_tabla = Forma_Tabla (cadena, &filas);
    printf ("\n\nDesea continuar ingresando palabras? (s/n) ");
    scanf ("%c", &rta);
} while (rta == 's');
printf("\n\n\nIngrese cantidad de caracteres alfabeticos: ");
scanf("%d",&longi);
fflush(stdin);
Busca_Muestra (longi, p_tabla, filas);
}


char * Ingresa_Cadena() {
static char p_cadena[25];
static int i=1;
printf("\n\nIngrese la palabra nro. %d: ",i);
scanf("%s",p_cadena);
i++;
return(p_cadena);
}


struct tab * Forma_Tabla(char * p_cadena, int * filas) {
static struct tab p_palabras[100];
char encontrado = 'N';
int i,cant_alfa,cant_caracteres;
for (i=0 ; i<*filas ; i++) {
    if (strcmp(p_cadena,p_palabras[i].cadena)==0) {
            encontrado = 'S';
            break;
    }
}
if (encontrado == 'N') {
    strcpy(p_palabras[*filas].cadena,p_cadena);
    cant_alfa=0;
    for (i=0; i<=strlen(p_cadena); i++) {
        if (isalpha(p_cadena[i])!=0) {
            cant_alfa++;
        }
    }
    p_palabras[*filas].alfa = cant_alfa;
    (*filas)++;
}
return p_palabras;
}


void Busca_Muestra (int longi, struct tab * p_tabla, int filas) {
int k=0;
for (k=0;k<filas;k++){
    if (p_tabla->alfa <= longi) {
        printf("\n%s",p_tabla->cadena);
        printf ("\nCant. carac. alfabeticos: %d\n", p_tabla->alfa);
    }
    p_tabla++;
}
}
