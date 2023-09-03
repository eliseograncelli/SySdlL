// Grancelli Eliseo (46935) com204
//Ej 14 de la practica de lenguajes
//Mostrar todas las palabras posibles de 3 simbolos con (z,x,y)

#include<stdio.h>
#include<string.h>

main()
{
    int i,j,f;
    char m[4]={'x','x','x','\0'};


printf("Palabras posibles de 3 simbolos con (x,y,z):\n");

for(f=0;f<3;f++) {
for (j=0;j<3;j++) {
    for(i=0;i<3;i++)
{printf("%s",m); printf ("\n"); m[0]++;}
m[0]='x';
m[1]++; }
m[1]='x';
m[2]++; }

printf("\n");
system ("pause");

}
