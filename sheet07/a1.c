#include <stdio.h>

#define N 11

void Weg (int x1, int y1, int x2, int y2,int *A){
    
    for (int i=x1-1; i<x2; i++) {
        for (int k=y1-1; k<y2; k++) {
            A[i*N+k]=1;
        }}
    
}



int maus (int x, int y,int *A){
    
    
    A[(x-1)*N+(y-1)]=3;
    
    return 0;
}


int main(){
    int A[N*N];
    int x,y;
    //Wand(*) ist 0
    for (int k=0; k<N; k++) {
    for (int i=0; i<N; i++) {
        A[i*N+k]=0;
    }}
    
    
    Weg(1, 10, 2, 10,A);
    Weg(2, 6, 2, 10,A);
    Weg(2, 3, 2, 4,A);
    Weg(3, 4, 3, 6,A);
    Weg(3, 2, 5, 2,A);
    Weg(4, 6, 4, 7,A);
    Weg(5, 2, 5, 6,A);
    Weg(4, 10, 10, 10,A);
    A[3*11+8]=1;
    Weg(5, 8, 8, 8,A);
    A[5*11+8]=1;
    Weg(6, 5, 6, 6,A);
    A[5*11+2]=1;
    Weg(7, 2, 7, 4,A);
    Weg(8, 4, 8, 8,A);
    Weg(9, 2, 9, 3,A);
    Weg(10, 2, 10, 9,A);
    A[9*11+5]=0;
    A[8*11+4]=1;
    A[10*11+6]=1;
    
    printf("Mauskoordinaten x y:\n");
    scanf(" %d %d",&x,&y);
    
    if (A[(x-1)*N+(y-1)]==0) {
        printf("Maus erstickt in Mauer\n");
        return 0;}
    
    int a=maus(x,y,A);
    
    for (int k=0; k<N; k++) {
        printf("\n");
        for (int i=0; i<N; i++) {
            printf("%d ",A[i*N+k]);
        }}
    
}
