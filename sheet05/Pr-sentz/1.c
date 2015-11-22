#include <stdio.h>

#define NMAX 3

 int dotprod(int A[NMAX],int B[NMAX]){
	int i,s=0;
	for(i=0;i<NMAX;i++){
	s+=A[i]*B[i];
	}
	return(s);
}
int main (){
	int s,i;
	int A[NMAX],B[NMAX];
	for(i=0;i<NMAX;i++){
		scanf("%d",&A[i]);
	}
	for(i=0;i<NMAX;i++){
		scanf("%d",&B[i]);	
	}
	dotprod(&A[NMAX-1],&B[NMAX-1]);
	printf("%d",s);
	return(0);
}
