#include <stdio.h>
#include <math.h>
#include <stdint.h>

long double e,v=1,x,y,z,F,a,c,n,Summe,abbruch,pi,ausgabeX;
int k,l;
long double f(long double x,int k){

    
    z=x;
    for (e=1; e<2*k+1; e=e+1) {
        x=z*x;
        }
    y=x;
    a=0;
    c=1;
    n=2*k+1;
    do {
        c=c*(a+1);
        a=a+1;
    } while (a<n);

    F=c;
    y=y/F;
    
    if (k%2==1) {
        y=-y;
    }
    return y;
}

int main (){
    pi=3.14159265358979323846264338328;
    printf("x=");
    scanf("%Lf",&x);
    ausgabeX=x;
    while (x>2*pi) {
        x=x-2*pi;
    }
    while (x<-2*pi) {
        x=x+2*pi;
    }
    k=10;
    y=0;
    for (k=0; k<10; k=k+1) {
        abbruch=y;
        y=f(x,k);
        if (fabsl(y-abbruch)<=e-20) {
            k=10;
        }
        Summe=Summe+y;
        
    }
    
    
    
    
    printf("sin(%.2Lf)=%.20Lf",ausgabeX,Summe);
    printf("\n");
    return 0;
}
