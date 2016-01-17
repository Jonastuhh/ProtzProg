#include <stdio.h>
#define PROBLEM problem1
int main (int argc,char*argv[]){
    

    
    FILE*PROBLEM=fopen(argv[1],"r");
    int N=0;
    int k=0;
    fscanf(PROBLEM,"%d",&N);						//Einlesen der Dimension 
    fscanf(PROBLEM,"%d",&k);						//Einlesen anzahl der aufgaben 
	float Mat[N][N];
    float LoesungsMat[k][N];
    float xMat[k][N];
	float LMat[N][N];
	float RMat[N][N];
    for (int i=0; i<N; i++) {						//Anfangsmatrix auslesen
        for (int j=0; j<N; j++) {
            fscanf(PROBLEM,"%f",&Mat[j][i]);
        }
    }
    for (int i=0; i<k; i++) {						// gesuchte Matrix auslesen
        for (int j=0; j<N; j++) {
            fscanf(PROBLEM,"%f",&LoesungsMat[j][i]);
        }
    }
	for(int i=0; i<N; i++) { 
													// Bestimmen von R 
        for(int j=i; j<N; j++) { 
            for(int k=0; k<i-1; k++){               
                RMat[i][j]=RMat[i][j]-(RMat[i][k] * RMat[k][j]); 
            } 
        } 
													// Bestimmen von L 
        for(int j=i+1; j<N; j++){ 
            for (int k = 0; k < i-1; k++){ 
                LMat[j][i]=LMat[j][i]-(LMat[j][k] * LMat[k][i]); 
            } 
            LMat[j][i]=LMat[j][i]/LMat[i][i]; 
        } 
    } 

	
	for (int i=0; i<N; i++) {						// Anfangsmatrix ausgeben
        for (int j=0; j<N; j++) {
            printf("%f\t",Mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
	
	for (int i=0; i<N; i++) {						// Rmatrix ausgeben
        for (int j=0; j<N; j++) {
            printf("%f\t",RMat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
	
	for (int i=0; i<N; i++) {						// Lmatrix ausgeben
        for (int j=0; j<N; j++) {
            printf("%f\t",LMat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
	return 0;
}
