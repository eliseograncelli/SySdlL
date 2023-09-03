#include <stdio.h>
#include <string.h>

struct tickCol {
    char cuerpo[200];
    char modulo[15];
 };

void carga_ticket (struct tickCol *, int *); //PROGRAMAR
char * identifica_modulo (char *); //NO PROGRAMAR
char * mayor_modulo(struct tickCol *, int, int *); //PROGRAMAR

main(){
struct tickCol p_ticket[200]; //pueden ingresarse 200 mails
int nroTicket=0,ocurrencias=0;
char rta, * p_modulo;
do{
    fflush(stdin);
    carga_ticket(p_ticket, &nroTicket); //llamamos a la función en el bucle
    printf ("\n\nDesea ingresar otro cuerpo de mail? (s/n) ");
    fflush(stdin);
    do {scanf("%c", &rta);} while(rta!= 's' && rta!= 'n');
    } while (rta == 's' && nroTicket <= 200); // se pueden cargar hasta 200 mail
system("cls");
p_modulo = mayor_modulo(p_ticket,nroTicket,&ocurrencias);
printf("El modulo de mayor ocurrencia es %s, tiene %d ocurrencias.\n\n", p_modulo, ocurrencias);
}


void carga_ticket(struct tickCol * p_tickets, int * numeroTicket) {
char cuerpoTicket[200], modulo[15]; //como maximo pueden haber 200 caracteres en el cuerpo del mail y 15 en el módulo
int cantLet=0;
system("cls");
puts("Ingrese el cuerpo del mail");
while ( (cuerpoTicket[cantLet]=getchar())!=EOF && cantLet<200 ) { (cantLet)++; }
cuerpoTicket[cantLet]='\0';
strcpy(modulo,identifica_modulo(cuerpoTicket)); //el modulo devuelto lo copiamos en un arreglo creado
if(strcmp(modulo,"***")==0) { //si no hay modulo correcto, devuelve ***
   printf("No se contabiliza el mail");
}  else {
   strcpy(p_tickets[*numeroTicket].cuerpo,cuerpoTicket);
   strcpy(p_tickets[*numeroTicket].modulo,modulo);
   printf("Incidencia nro. %d registrada",*numeroTicket+1);
   (*numeroTicket)++;
}
}

char * identifica_modulo(char * cuerpo) {
static char modulo[15];
int i=0;
strcpy(modulo,"***");
while (cuerpo[i]!=':' && cuerpo[i]!='\0') {
    modulo[i]=cuerpo[i];
    i++;
}
modulo[i]='\0';
if(strcmp(modulo,"Hotel")!=0 && strcmp(modulo,"Vuelo")!=0 && strcmp(modulo,"Paquete")!=0) {strcpy(modulo,"***");}
return modulo;
}


char * mayor_modulo(struct tickCol* p_tickets,int cantMail,int * ocurrencia) {
int i, cHotel=0, cPaquete=0, cVuelo=0;
static char modulo[15];
for(i=0;i<cantMail;i++) {
    if(strcmp(p_tickets[i].modulo,"Hotel")==0) {cHotel++;}
    if(strcmp(p_tickets[i].modulo,"Paquete")==0) {cPaquete++;}
    if(strcmp(p_tickets[i].modulo,"Vuelo")==0) {cVuelo++;}
}
if(cHotel>=cPaquete && cHotel>=cVuelo) {
        strcpy(modulo,"Hotel");
        *ocurrencia = cHotel;
} else if(cPaquete>=cHotel && cPaquete>=cVuelo) {
        strcpy(modulo,"Paquete");
        *ocurrencia = cPaquete;
        } else {
            strcpy(modulo,"Vuelo");
            *ocurrencia = cVuelo;
        }
return modulo;
}
