#include <stdio.h>
#include <math.h>
#include <stdint.h>

long double k,e,v=1,x,y,z,F,a,c,n,Summe;

long double f(x,k){

    
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
    x=2.0;
    k=10;
    for (k; k>=0; k=k-1) {
        y=f(x,k);
        Summe=Summe+y;
    }
    
    
    
    
    printf("%.20Lf",Summe);
    printf("\n");
    return 0;
}

