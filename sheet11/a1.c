#include <stdio.h>

int main (int argc,char*argv[]){
    

    
    FILE*problem=fopen(argv[1],"r");
    int N=0;
    int k=0;
    fscanf(problem,"%d",&N);
    fscanf(problem,"%d",&k);
    float Mat[N][N];
    float LoesungsMat[k][N];
    float xMat[k][N];
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            fscanf(problem,"%f",&Mat[i][j]);
        }
    }
    for (int i=0; i<k; i++) {
        for (int j=0; j<N; j++) {
            fscanf(problem,"%f",&LoesungsMat[i][j]);
        }
    }

    
    //Dreiecksmatrix erzeugen
    for (int spalte=0; spalte<N-1; spalte++) {                   //spalte, die mit nullen unter der diagonalen gefüllt werden soll
        
        
    for (int zeile=spalte+1; zeile<N; zeile++) {               //Zeile, die mit null beginnen soll
    
    float Verhaeltnis=Mat[zeile][spalte]/Mat[spalte][spalte];        //Verhältnis zwischen zeile darüber und aktueller zeile
    
    
    for (int i=0; i<N; i++) {
        Mat[zeile][i]=Mat[zeile][i]-Mat[spalte][i]*Verhaeltnis;       //zeile von anderer zeile abziehen, sodass vorne eine Null steht
    }
        
    }}
    
    
    
   /*
    //Rückwärtssubtitution
    
    for (int zeile=1; zeile<=1; zeile++) {
    xMat[N-zeile][0]=LoesungsMat[N-zeile][0]/Mat[N-zeile][N-zeile];             //nach x aufgelöst
    
  //  xMat[k-1][N-2]=LoesungsMat[k-1][N-2]-(xMat[k-1][N-1]*Mat[N-2][N-1]);
    }
*/
    
    
    
    //Ausgabe der Matrizen
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("%f\t",Mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
/*
    for (int i=0; i<k; i++) {
        for (int j=0; j<N; j++) {
            printf("%f\t",LoesungsMat[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i=0; i<k; i++) {
        for (int j=0; j<N; j++) {
            printf("%f\t",xMat[i][j]);
        }
        printf("\n");
    }
    */
    return 0;
}
