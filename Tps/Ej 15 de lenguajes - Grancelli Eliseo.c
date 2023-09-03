// Grancelli Eliseo (46935) com 204
// 15. Dada una cadena de 6 símbolos, verificar si pertenece al lenguaje L = {a, b, c, d, x, y, z}
// y además mostrar todos los prefijos y sufijos propiamente dichos.

#include <stdio.h>
#include <string.h>
#include <conio.h>

main()
{
    int i,j,k;
    char m[8]={'a','b','c','d','x','y','z','\0'}, m2[7], q;


    printf ("Ingrese una cadena de 6 simbolos: ");
    for (i=0;i<6;i++)
    m2[i]=getchar();
    printf("\n");

    for (i=0;i<6;i++)
        if ((m2[i]=='a') || (m2[i]=='b') || (m2[i]=='c') || (m2[i]=='d') || (m2[i]=='x') || (m2[i]=='y') || (m2[i]=='z'))
        j=1;
    else {j=0; printf ("La cadena ingresada no pertencece al lenguaje L = {a, b, c, d, x, y, z}.\n"); break; }

    if (j==0);
    else
    {
            printf ("\nPrefijos propiamente dichos de la cadena \"%s\":\n",m2);

        for (k=5;k>0;k--) {
            for (j=0;j<k;j++)
            printf ("%c",m2[j]);
            printf ("\t"); }


            printf ("\n\nSufijos propiamente dichos de la cadena \"%s\":\n",m2);

        for (k=1;k>0 && k!=6;k++) {
            for (j=k;j!=6;j++)
            printf ("%c",m2[j]);
            printf ("\t");}
            printf ("\n");



            }
printf ("\n");
system ("pause");
}
