#include <stdio.h>
#include <math.h>
#include <stdint.h>

long double k,x,y,e,z,l,Summe;
long double f(long double x, int k){
	
	x=(x-1);
	z=x;
	l=k+1;
	for(e=1; e<(l); e=e+1){						
		x=z*x;
	}
	x=x/l;										
	
	y=x;										
	if(k%2==1){
		y=-y;
	}
	
	return y;
}

int main(){
	x=1;
	
	
	for (k=0; k<10; k=k+1) {
       
        y=f(x,k);
        if (y<=e-20) {
            k=10;
        }
        Summe=Summe+y;
        
    }

	int y = f(x,k);
	printf("ln(%lf) = %lf\n",x, Summe);
	
}
