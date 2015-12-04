#include <stdio.h>
#include <math.h>

int n_max=1000;

int mandel(double x1,double y1,double xn, double yn, int n, int n_max){
    if (n>=n_max) {
        return n;
    }
    double xn1=xn*xn-yn*yn+x1;  //komplexe zahl ausmultipliziert realanteil
    double yn1=2*xn*yn+y1;      //imaginäranteil
    printf("z(%d)\t= %f+%fi\t|z|=%f\n",n,xn1,yn1,sqrt(xn1*xn1+yn1*yn1)); //gibt komplexe zahl und Betrag aus
    
    if (xn1*xn1+yn1*yn1>=4) {   //abbruch ohne wurzel
        return n;
    }
    n++;
    n=mandel(x1, y1,xn1,yn1, n, n_max );
    return n;
}


int main (){
    double x1,y1;
    int n;
    printf("Gebe eine komplexe Zahl ein:");
    scanf("%lf + %lfi",&x1,&y1);
    n=mandel(x1,y1, 0,0,1,n_max);
    printf("Rekursionstiefe:%d\n",n);
    return 0;
}
