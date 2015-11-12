#include <stdio.h>
#include <math.h>
#include <stdint.h>

long double k,x,y,e,z,l;
long double f(long double x, int k){
	
	z=x;
	l=2*k+1;
	for(e=1; e<(l); e=e+1){						//x^(2k+1)
		x=z*x;
	}
	x=x/l;										//(x^(2k+1))/(2k+1)
	
	y=x;										//(-1)^k
	if(k%2==1){
		y=-y;
	}
	
	return y;
}

int main(){
	x=3;
	k=1;
	
	for(k=0)
	int y = f(x,k);
	printf("arctan(x) = %d\n", y);
	
}
