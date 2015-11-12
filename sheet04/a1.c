#include <stdio.h>
#include <math.h>

long double k,e,v=1,x,y;

long double f(x,k){
    
    for (e=0; e<k; e++) {
        v=v*-1;
        y=v;
    }
    return y;
}

int main (){
    x=1;
    k=3;
    y=f(x,k);
    printf("%Lf",y);
    printf("\n");
}
