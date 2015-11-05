#include <stdio.h>

int main(){
    int n=10,m,o,y=n,a=2*n,x=-n;
    o=3*n+1;
    m=o;                //Anzahl der Leerzeichen
    if (n<30) {
        
    
    
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
    
    
    while (a>-2*n-2) {
    
        
     while(m>0)    {
       if (a>0||a<-1)
        printf(" ");
        m=m-1;
    } ;
        if (a>0||a<-1) {
            
        
        printf("|");
        if (a%2==0) {
            if (y>0) {
                printf(" ");
            }
            printf("%d",y);
            y=y-1;
        }
        }
        else{
            
            if (a==0) {
                m=o;
                while(m>0)    {
                        printf("-");
                    m=m-1;
                } ;
                printf("+");
                m=o;
                while(m>0)    {
                    printf("-");
                    m=m-1;
                } ;
                printf("> x");

            }
            if (a==-1) {
                while (x<=n) {
                    
                    if (x>=0) {
                        printf(" ");
                    }

                    if (x==0) {
                        printf("| ");
                        x=x+1;
                    }
                    else {
                printf("%d",x);
                        if (x>=-9&&x<=9) {
                            printf(" ");
                        }
                                        x=x+1;
                    }
                }
                y=-1;
            }
            
          
        
        }
        
        a=a-1;
        printf("\n");
        m=o;
        
    
    }}
    else
        printf("Fenster zu klein, wähle kleineres N! :D\n\n");
    
    return 0;
    }
