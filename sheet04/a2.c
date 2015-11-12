#include <stdio.h>
#include <math.h>

long double k,v=1,x,y,e;

long double c(x,k){

for(e=0;e<k;e++){
	v=v*-1;
	y=v;
	}
	return y;
}

int main(){
	x=1;
	k=1;
	y=c(x,k);
	printf("%Lf",y);
}
