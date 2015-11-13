#include <stdio.h>
#include <math.h>

long double x,y=1,z,a,c,n=-1,Summe1=0,Summe2=0,Summe3=0;
int k,e;

long double f(long double x){
    x=fmod(x,2*M_PI);                       //fmod ist modulo für Kommazahlen //bringt x in den Bereich zwischen -2pi bis 2pi
    z=x;
    for (k=0; fabsl(y)>1e-16; k=k+1) {      //erhöht k und summiert
        x=z,n=n+2,c=1;                      //n+2=(2k+1)
    for (e=1; e<n; e=e+1) {                 //(x^2k+1)
        x=z*x;
    }
        for (a=0; a<n; a++) {               //Fakultät
        c=c*(a+1);
    }
    y=x/c;
        if (k%2==1)                         //Vorzeichen
            y=-y;
    Summe1=Summe1+y;
    }
    return Summe1;
}
long double g(long double x){
    z=x,y=1,n=-1,e=1;
    for (k=0; fabsl(y)>1e-16&&k<20000; k++) {   //erhöht k und summiert //maximale Genauigkeit bis k=20000
        x=z,n=n+2;                              //n+2=(2k+1)
        for (e=1; e<n; e=e+1) {                 //(x^2k+1)
            x=z*x;
        }
        y=x/n;
        if (k%2==1)                             //Vorzeichen
            y=-y;
        Summe2=Summe2+y;
    }
    return Summe2;
}
long double h(long double x){
    z=(x-1),y=1,n=0,e=1;
    for (k=0; fabsl(y)>1e-16&&k<20000; k++) {   //erhöht k und summiert //maximale Genauigkeit bis k=20000 aus Zeitgründen
        x=z,n++;                                //n++=k+1
        for (e=1; e<n; e=e+1) {                 //(x^2k+1)
            x=z*x;
        }
        y=x/n;
        if (k%2==1)                             //Vorzeichen
            y=-y;
        Summe3=Summe3+y;
    }
    return Summe3;
}
int main (){
    printf("x=");
    scanf("%Lf",&x);
    Summe1=f(x);
    printf("\nAnnäherung(x)\t\t= %.20Lf\nsin(x)\t\t\t= %.20lf\nDifferenz\t\t= %.20Lf\n\n",Summe1,sin(x),Summe1-sin(x));
    if (x>=-1&&x<=1){
        Summe2=g(x);
        printf("Annäherung(x)\t\t= %.20Lf\natan(x)\t\t\t= %.20lf\nDifferenz\t\t= %.20Lf\n\n",Summe2,atan(x),Summe2-atan(x));
}
    else printf("x liegt nicht im Defintionsbereich [-1,1] der Annäherung für arcustangens\n\n");
    if (x>0&&x<=2){
        Summe3=h(x);
        printf("Annäherung(x)\t\t= %.20Lf\nln(x)\t\t\t= %.20lf\nDifferenz\t\t= %.20Lf\n\n",Summe3,log(x),Summe3-log(x));
    }
    else printf("x liegt nicht im Defintionsbereich ]0,2] der Annäherung für den Logarithmus\n\n");
    return 0;
}
