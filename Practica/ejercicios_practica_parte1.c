/* Esta primera parte incluye algunos ejercicios correspondientes a:
   Variables, constantes, operadores y expresiones.
   Funciones de Entrada y Salida.
*/


//#include <stdio.h>
/* 17.
main() {
       int a=2, b=3, c=4;
       int result;
       //result = a * b % c;
       //result = 3 * (a -= 1) + 1 % a;
       result = (a > b) || (b == c);
       printf("%d\n", result);
       system ("pause");
} */

/* 18-d.
main() {
int a = 10;
float c, d, b = 4;
c = b / a;
d = (int) b / a;
printf("%f \n ", c);
printf("%f \n ", d);
printf("%g \n ", d);
printf("%g \n ", c);
//system ("pause"));
getchar();
} */

/* 18-e.
main() {
char c ; int i ; float f ;
c = i = f = 60 + 5.8;
printf ("%c %d %f \n", c, i ,f) ;
} */

/* 18-f.
main() {
char c ; int i ; float f ;
c = i = f = 'A' + 5 ;
printf(" %c %d %f ", c, i, f);
} */

/* 18-g.
main() {
char c ; int i ; float f ;
c = i = f = 'A' + 5.9 ;
printf (" %c %d %f \n", c, i, f) ;
} */

/* 18-h.
main() {
char c ; int i ; float f ;
c = i = f = 'A' + 3.3 + 5;
printf(" %c %d %f ", c, i, f) ;
} */

/* 18-i.
main() {
int a = 1, b = 5;
printf("%d\t", a == 2 );
printf("%d\n", 5 / 2 * 3 + 8 % 5 + b);
} */

/* 18-j.
main() {
int a =1, b = 5;
printf("%d\t", a == 1);
printf("%d\n", b + 7 / 3 * 3 + 7 % 5 );
} */

/* 18-k.
main() {
       int a, b, c;
       a = 5;
       b = ++a;
       c = ( a + 5 * 2 ) * ( b + 6 / 2 ) + ( a * 2 );
       printf("%i, %i, %i", a, b, c );
       //system ("pause");
} */





/* 27.
#include <stdio.h>
main() {
long int x;
//int x;
//float y;
//char x;
char y;
//scanf("%d,%f",&x,&y);
//scanf("%c%d",&x,&y);
//scanf("%c/%d",&x,&y);
scanf("%ld %c",&x,&y);
//fflush;
//printf("Los numeros ingresados son %ld y %c",x,y);
printf("\n\n%ld\t%c",x,y);
} */

/* 29.
#include <stdio.h>
main() {
    char caracter;
    //int caracter;
    printf("Ingrese un caracter: ");
    //scanf("%c", &caracter);
    caracter=getche();
    printf ("\nEl numero decimal de la tabla ASCII del caracter %c es %d \n\n",caracter, caracter);
} */


/* .31
#include <stdio.h>
main()
{   char cad[20];
    int num;
    scanf("%d*%s",&num,cad);
    printf("El valor ingresado es %d y la cadena es \"%s\"  \n\n",num,cad);
} */


/* 33.
#include <stdio.h>
#include <math.h>
main()
{
int nro;
double cuadrado,cubo;
printf("Ingrese un Numero: ");
scanf("%d", &nro);
printf("\nNumero\tCuadrado\tCubo");
//cuadrado = nro * nro;
//cubo = nro * nro * nro;
cuadrado = pow(nro,2);
cubo = pow(nro,3);
printf("\n%d\t%5.0f\t\t%5.0f",nro,cuadrado,cubo);
} */


/* 34.
#include <stdio.h>
#include <math.h>
#define PI 3.141592
main()
{
	float radio, diametro, circunferencia, area;
	printf("Introduce el radio de un circulo: ");
	scanf("%f", &radio);
	diametro = radio * 2;
	circunferencia = diametro * PI;
	area = PI * pow(radio,2);
	printf("\nEl diametro del circulo \"radio * 2\" es: %5.2f \n", diametro);
	printf("\nLa circunferencia del circulo \"PI * diametro\" es: %5.2f \n", circunferencia);
	printf("\nEl area del circulo \"PI * (radio^2)\" es: %5.2f \n", area);
} */


/* 48.*/
main() {
int a,b,c;
scanf("%3d %3d %3d",&a,&b,&c);
printf("%d %d %d",a,b,c);
}
