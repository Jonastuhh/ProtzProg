#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

#define N 100

char buffer[N];

int main (){
    int p=0;
    int size=0;
    int *Ar = NULL;
    int nr=0;
    
    while (p!=8){
    
    printf("1) Array−Größe festlegen\t\t");
    printf("4) Bubblesort (downwards)\t");
    printf("7) Mergesort\n");
    printf("2) Zahlen von Tastatur einlesen\t\t");
    printf("5) Shakersort\t\t\t");
    printf("8) Programm beenden\n");
    printf("3) Zufallszahlen erzeugen\t\t");
    printf("6) Insertionsort\n");
    
    printf("Programmnummer:\t");
        
        scanf(" %d",&p);
        //1. Lese max. N-1 Zeichen in Puffer ein
        /*fgets (buffer, N, stdin);
        if (sscanf(buffer," %d",&p)<1){
            printf("FEHLER: Bitte Zahle eingeben.\n");
        }
        printf("%d\n",p);*/

    if (p==1) {
        printf("Array−Größe festlegen:\t");
        scanf(" %d",&size);
        /*fgets (buffer, N, stdin);
        if (sscanf(buffer," %d",&p)<1){
            printf("FEHLER: Bitte Zahle eingeben.\n");
        }*/


        Ar=(int*)malloc(size*sizeof(int));

    }
    
    if (p==2) {
            for (int i=0; i<size; i++) {
                while (nr<1||nr>1000) {
                    scanf(" %d",&nr);
                    if (nr<1||nr>1000) {
                        printf("Zahl nicht zwischen 1 und 1000\n");
                    }
                }
                
                Ar[i]=nr;
                nr=0;
            }}
        
    if (p==3) {
        for (int i=0; i<size; i++) {
            Ar[i]=rand()%1000+1;
        }}
        
    if (p==4) {
        bubblesort(Ar,size);
        }

    if (p==5) {
        shakersort(Ar,size);
        }
        
    if (p==6) {
        insertionsort(Ar,size);
        }

    if (p>1&&p<8) {
        for (int i=0; i<size; i++){
        printf("%5d",Ar[i]);
            if (i%10==9) {
                printf("\n");
                }
            }
        
        
        
        printf("\n");}
    
       
        
        
    }
    
    
    
    
    free(Ar);
    
    return 0;
}
