#include <stdio.h>


int mayor();
float prom();
struct aaa{
 int a[10];
};

struct aaa aa;

main()
{
int n;
printf("Ingrese 10 numeros\n");
for (int i=0;i<10;i++)
scanf("%i",&aa.a[i]);
printf("Los numeros ingresados son:\n");
for (int i=0;i<10;i++)
{
   printf("%i ",aa.a[i]);
}
printf("\n");
printf("\nEl mayor de ellos es: %i\n",mayor());
printf("\n");
printf("El promedio es: %5.2f\n",prom());
}

int mayor()
{
    int may=0;
 for (int i=0;i<10;i++){
    if (aa.a[i]>may)
     may=aa.a[i];
    }
    return(may);
}

float prom()
{
    int sum=0;
    float pro;
 for (int i=0;i<10;i++){
     sum+=aa.a[i];
    }
    pro=(float)sum/10;
return(pro);
}
