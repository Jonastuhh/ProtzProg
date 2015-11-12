#include <stdio.h>
#include <math.h>
#include <stdint.h>

long double k,x,y,e,z,l;
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
	k=2;
	
	int y = f(x,k);
	printf("ln(%lf) = %lf\n",x, y);
	
}
