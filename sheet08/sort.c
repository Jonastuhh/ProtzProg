#include "sort.h"

void bubblesort(int Ar[],int size){
    int swap;
    
    
    for (int i=0;i<size-1;i++)
    {
        for (int j=0 ;j<size-i-1;j++)
        {
            if (Ar[j]>Ar[j+1])
            {
                swap=Ar[j];
                Ar[j]   = Ar[j+1];
                Ar[j+1] = swap;
            }
        }
    }
}


void shakersort(int *Ar,int size){
    int j=0,swap;
    for (int i=0;i<size-1;i++)
        j=i;
 {
    while (j>0&&Ar[j]<Ar[j-1]) {
        swap=Ar[j];
        Ar[j]=Ar[j-1];
        Ar[j-1]=swap;
        j--;
    }
 }}


void insertionsort(int *Ar,int size){
    int j;
for (int i=1;i<size; i++) {
    int swap=Ar[i];
    j=i-1;
    while ((swap<Ar[j])&&(j>=0)) {
        Ar[j+1]=Ar[j];
        j--;
    }
    Ar[j+1]=swap;
}}


