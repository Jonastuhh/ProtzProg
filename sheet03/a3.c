#include <stdio.h>

int main(){

    float r=-20.65625;
    int e=0,f=128,a=0;
    
    if (r<0) {                  //Vorzeichenbit
        printf("1");
        r=-r;
    }
    else printf("0");
    
    while (r>=2) {              //Bestimmung des Exponenten
        r=r/2;
        e=e+1;
    }
    
    while (r<1) {
        r=r*2;
        e=e-1;
    }
    
    e=e+127;
    
    while (a<8) {               //Exponent wird in binär umgerechnet
        
    if (e>=f) {                 //f=128
        printf("1");
        e=e-f;
    }
    else printf("0");
        
    e=e*2;
    a=a+1;
    }
    
    r=r-1;                      //implizite eins wird abgezogen
    a=0;
    while (a<23) {              //Mantisse
    r=r*2;
    if (r>=1) {
        printf("1");
        r=r-1;
    }
    else printf("0");
        a=a+1;
    }
    printf("\n");
    return 0;
}
