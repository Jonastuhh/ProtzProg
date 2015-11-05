#include <stdio.h>

int main(){
    int n=3,m,o,y=n,a=2*n;
    o=3*n+1;
    m=o;                //Anzahl der Leerzeichen
    
    
    {
    
    do {
        printf(" ");
        m=m-1;
    } while(m>0);
    printf("y\n");
    
    m=o;
    do {
        printf(" ");
        m=m-1;
    } while(m>0);
    printf("^\n");
}               //Oberen 2 Zeilen
    m=o;
    
    
    while (a>0) {
    
        
     while(m>0)    {
        printf(" ");
        m=m-1;
    } ;
    
        printf("|");
        if (a%2==0) {
            printf(" %d",y);
            y=y-1;
        }
        
        a=a-1;
        printf("\n");
        m=o;
        
    
    }
    
    
    
    }
