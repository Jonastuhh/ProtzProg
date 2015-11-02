/**
 * Prozedurale Programmierung WS 15/16
 *
 * Integer Arithmetik
 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main() {
    int16_t a;
    int16_t b;
    b=1;
    a=0;
    while (b>a)
    {
    b=a+2;
    a=a+1;
    }
    printf("Intervall für  int16_t: {%d,",b);
        printf("%d}\n",a);
        
        
        uint16_t c;
        uint16_t d;
        d=1;
        c=0;
        while (d>c)
        {
            d=c+2;
            c=c+1;
        }
        printf("Intervall für uint16_t: {%d,",d);
            printf("%u}\n",c);
            
            int64_t e;
            int64_t f;
            f=1;
            e=0;
            while (f>0)
            {
                f=powl(2, e+1) ;
                e=e+1;
            }
    e=-1-f;
            printf("Intervall für  int64_t: {%lld,",f);
                printf("%lld}\n",e);
    
    uint64_t g;
    uint64_t h;
    h=1;
    g=0;
    while (h>0)
    {
        g=g+1;
        h=pow(2,g) ;
    }
    g=-1+powl(2, g);
    printf("Intervall für uint64_t: {%llu,",h);
    printf("%llu}\n",g);
    
    
}
