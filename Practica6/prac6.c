#include <stdio.h>
#include <stdlib.h>

void GeneradorAleatorio(double *Numaleat,int a,int b,int N)
{

    /* Generacion de N numeros random en el intervalo [a,b)*/

    int i;
    for(i=0; i<N; i++)
    {

        Numaleat[i]=a+(b-a)*(rand()/((double)RAND_MAX+1));
    }
}

void Histogram(double *data, double *Hist, int N_data, int N_intervalos, double *d, double *m, double *M)
{

    int i, Indice;
    double min,max,delta, Norm;
    min=1000000;
    max=-1000000;
    for(i=0; i<N_intervalos; i++)Hist[i]=0;
    for(i=0; i<N_data; i++)
    {
        if(data[i]<min)min=data[i];
        if(max<data[i])max=data[i];
    }
    delta=(max-min)/N_intervalos;


    if (delta==0)printf("Error: No se pueden calcular los intervalos; Max=%lf, Min=%lf\n",max,min);

    for(i=0; i<N_data; i++)
    {

        Indice=(data[i]-min)/delta;
        if(Indice==N_intervalos)Indice=N_intervalos-1;
        Hist[Indice]++;
    }

    *d=delta;
    *m=min;
    *M=max;

    Norm=1.0/(N_data*delta);
    for(i=0; i<N_intervalos; i++)Hist[i]*=Norm;
}

void med_var(double *serie, int Numero, double *media, double *varianza){

    int i,j;
    double med=0,var=0;
    for(i=0;i<Numero;i++){
        med=med+serie[i];}
    *media=med/(float)Numero;

    for(j=0;j<Numero;j++){
        var=var+(serie[j]-*media)*(serie[j]-*media);
    }
    *varianza=var/(float)(Numero-1);


}


