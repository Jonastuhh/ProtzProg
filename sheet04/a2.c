#include <stdio.h>

int f=20;    //Schriftgröße

int Überschrift (int g){
    printf("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");		// größe des Fensters
    printf("<svg xmlns=\"http://www.w3.org/2000/svg\"\n");
    printf("     xmlns:xlink=\"http://www.w3.org/1999/xlink\"\n");
    printf("     xmlns:ev=\"http://www.w3.org/2001/xml-events\"\n");
    printf("     version=\"1.1\"\n");
    printf("     baseProfile=\"full\"\n");
    printf("     width=\"%d\"\n",g);
    printf("     height=\"%d\">\n\n",g);
    
    return 0;
}


int Linie (int x1,int  y1,int x2,int y2){
    
    printf("<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\" \
           stroke-width=\"2\" />\n", x1, y1, x2, y2);
    
    return 0;
}


int Text (int x1,int y1, char tex){
    
    printf("<text x=\"%d\" y=\"%d\" font-size=\"%d\">%c</text>\n",x1,y1,f,tex); // >
    return 0;
}

int Dreieck (int x1,int y1,int Drehung){
    int ax,ay,bx,by,cx,cy;
    int size=8;
    ax=x1-size;
    ay=y1+size;
    bx=x1+size;
    by=y1+size;
    cx=x1;
    cy=y1-size;
    
    
    printf("<path d=\"M%d %d L%d %d L%d %d Z\" transform=\"rotate(%d %d %d)\" style=\"stroke:black;stroke-width:3;fill:black;\" />",cx,cy,bx,by,ax,ay,Drehung,x1,y1);
    return 0;
}




int Zahlen (int x1,int y1, int Zahl){
    if (Zahl!=0) {
    printf("<text x=\"%d\" y=\"%d\" font-size=\"%d\">%d</text>\n",x1,y1,f,Zahl); // >
    }
    return 0;
}


int main (){

    int n=10,x1,x2,y1,y2,g ;  // n gibt man ein, g gesammt größe ; k zum zählen
    int Abstand=40;             //zum Rand und zwischen den Zahlen
    int Zahl;
    
    if (n<=0) {
        n=1;
    }
    
    if (n>30) {
        n=30;
    }
    
    
    
//Überschrift SVG
    
    g=n*2*Abstand+2*Abstand;
    Überschrift(g);
    
//x-Achse
    
    x1=Abstand;
    x2=g-Abstand;
    y1=y2=g/2;
    Linie(x1, y1, x2, y2);
    
//x-Pfeil
    
    x1=g/2;
    y1=Abstand-5;
    Dreieck(x1,y1,0);
    
    
//y-Achse
    
    y1=Abstand;
    y2=g-Abstand;
    x1=x2=g/2;
    Linie(x1, y1, x2, y2);
    
//y-Pfeil
    
    y1=g/2;
    x1=g-Abstand+5;
    Dreieck(x1,y1,90);
    
//X-Achsen-Beschriftung
    
    x1=Abstand-8;
    y1=g/2+25;
    Zahl=-n;
    
    while (Zahl<=n){
        
    Zahlen(x1, y1, Zahl);
        
        x1=x1+Abstand;
    Zahl++;
    }
    
//Y-Achsen-Beschriftung
    
    y1=g-Abstand+5;
    x1=g/2+15;
    Zahl=-n;
    
    while (Zahl<=n){
        
        Zahlen(x1, y1, Zahl);
        
        y1=y1-Abstand;
        Zahl++;
    }
    

    
    
    
    
    printf("</svg>");
    return 0;
}
