#include <stdio.h>
#include <stdint.h>
#include <math.h>
int main (){
    uint16_t  b=0,a=11,d=0,c=16;  //d=1 Ausgabe aller Stellen
    
    
    if (a==0&&d==0)               //für den Fall a=0
        printf("0");
    
    while (c>0) {
        
    
    b=pow(2,c-1);
    
    if (a>=b) {
        printf("1");
        a=a-b;
        d=1;
       
    }
    else {
        if (d)              //Es wird erst eine Null ausgegeben, wenn bereits eine 1 ausgegeben wurde
            printf("0");
    }
        c=c-1;
    }
    
    
    printf("\n");
    return 0;
}
