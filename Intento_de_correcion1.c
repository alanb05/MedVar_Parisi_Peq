#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NormRANu (2.3283063671E-10F)
#define Frec_Max 100
unsigned int irr[256];
unsigned int ir1;
unsigned char ind_ran,ig1,ig2,ig3;
int frec[Frec_Max];

float Random(){

    float r;
    ig1=ind_ran-24;
    ig2=ind_ran-55;
    ig3=ind_ran-61;
    irr[ind_ran]=irr[ig1]+irr[ig2];
    ir1=(irr[ind_ran]^irr[ig3]);
    ind_ran++;
    r=ir1*NormRANu;
    //printf("r=%f\n",r);
    return r;

}

void ini_ran(int SEMILLA)
{
    int INI,FACTOR,SUM,i;
    srand(SEMILLA);
    INI=SEMILLA;
    FACTOR=67397;
    SUM=7364893;
    for(i=0;i<256;i++)
    {
    INI=(INI*FACTOR+SUM);
    irr[i]=INI;
    }
    ind_ran=ig1=ig2=ig3=0;
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

int main ()
{
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
    //Apartado 6.2

    ini_ran(36);
    int N=100000,i,max=10,min=-10;
    double data[Frec_Max],epsilon=0.1,cambio,cociente,x,xnew,media,varianza;
    x=Random();
    double delta=(max-min)/100.;

    ini_ran(123); //Porque???

    for (i=0;i<Frec_Max;i++){
        data[i]=0;
    }

    for(i=1;i<N;i++){
        cambio=epsilon*2*(Random()-0.5);
        xnew=x+cambio;
        if(xnew>max)xnew=xnew-(max-min);
        if(xnew<min)xnew=xnew+(max-min);

        cociente=exp(-5*(xnew*xnew-x*x));

        if(Random()<cociente)x=xnew;

        data[(int)((x-min)/delta)]++;

        }
     med_var(data,N,&media,&varianza);
     printf("%d %lf %lf %lf\n",N, media,varianza,sqrt(varianza));

return 0;
}
