#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* APARTADO 6.1
int main ()
{
 int Numero,i;
 double media, varianza;

 FILE*f;
 f=fopen("resultados.txt","w");
 for(i=1;i<=5;i++){
    Numero=pow(10,i);
    printf("%d\n",Numero);
    double data[Numero];
    GeneradorAleatorio(data,-2,5,Numero);
    med_var(data,Numero,&media,&varianza);
    fprintf(f,"%d %lf %lf %lf\n",Numero, media,varianza,sqrt(varianza));

 }

 return 0;
} */

    int main(){

     /*Pequeños cambiossss*/
    int N=10000,i;
    double data[N],min=-3,max=10,delta,nombre,epsilon=0.1,cambio,x0;
    x0=min+(max-min)*(rand()/((double)RAND_MAX+1));
    data[0]=x0;

    int N_intervalos=100;
    double Histograma[N_intervalos];
    FILE*f=fopen("hist.txt","w");

    for(i=1;i<N;i++){
        cambio=epsilon*2*(rand()/((double)RAND_MAX+1));
        data[i]=data[i-1]+cambio;
        if(data[i]>max)data[i]=data[i]-(max-min);
        if(data[i]<min)data[i]=data[i]+(max-min);
    }
    Histogram(data,Histograma,N,N_intervalos,&delta,&min,&max);
     for (i=0; i<N_intervalos; i++)
    {
        fprintf(f,"%lf %lf\n ",min+delta*i,Histograma[i]);
    }

    fclose(f);









    return 0;
    }
