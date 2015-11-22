#include <stdio.h>
#include <math.h>

#define FUNKTION1 sin(x)
#define FUNKTION2 cos(x)
#define SVG_HEIGHT 600
#define SVG_WIDTH 800
#define X_MIN -6
#define X_MAX 10
#define Y_MIN -2
#define Y_MAX 2
#define GEN 0.1
#define Abstand 40

int f=20;    //Schriftgröße

int Überschrift (){
    printf("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");		// größe des Fensters
    printf("<svg xmlns=\"http://www.w3.org/2000/svg\"\n");
    printf("     xmlns:xlink=\"http://www.w3.org/1999/xlink\"\n");
    printf("     xmlns:ev=\"http://www.w3.org/2001/xml-events\"\n");
    printf("     version=\"1.1\"\n");
    printf("     baseProfile=\"full\"\n");
    printf("     width=\"%d\"\n",SVG_WIDTH);
    printf("     height=\"%d\">\n\n",SVG_HEIGHT);
    
    return 0;
}


int Linie (int x1,int  y1,int x2,int y2, char Farbe[10]){
    
    printf("<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"%s\" \
           stroke-width=\"3\" />\n", x1, y1, x2, y2, Farbe);
    
    return 0;
}

int kLinie (int x1,int  y1,int x2,int y2){
    
    printf("<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"grey\" \
           stroke-width=\"0.25\" />\n", x1, y1, x2, y2);
    
    return 0;
}




int Text (int x1,int y1, char tex[30]){
    
    printf("<text x=\"%d\" y=\"%d\" font-size=\"%d\">%s</text>\n",x1,y1,f,tex);
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


int Rechteck (int x1, int y1,int x2,int y2,char Farbe[10]){
    printf("<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" stroke=\"%s\"            stroke-width=\"1\" fill=\"%s\" />",x1,y1,x2-x1,y2-y1,"black",Farbe);
    
    return 0;
}



int Zahlen (int x1,int y1, int Zahl){
    if (Zahl!=0) {
    printf("<text x=\"%d\" y=\"%d\" font-size=\"%d\">%d</text>\n",x1,y1,f,Zahl);
    }
    return 0;
}


float x_svg2mat (float x_svg){

    float x_mat=X_MIN+((x_svg-Abstand)*(X_MAX-X_MIN))/(SVG_WIDTH-2*Abstand);
    return x_mat;
}

float y_svg2mat (float y_svg){
    
    float y_mat=Y_MIN+(-(y_svg-Abstand)/(SVG_HEIGHT-2*Abstand)+1)*(Y_MAX-Y_MIN);
    return y_mat;
}


float x_mat2svg (float x_mat){
    
    float x_svg=Abstand+((x_mat-X_MIN)*(SVG_WIDTH-2*Abstand))/(X_MAX-X_MIN);
    return x_svg;
}


float y_mat2svg (float y_mat){
    
    float y_svg=Abstand+(1-((y_mat-Y_MIN))/(Y_MAX-Y_MIN))*(SVG_HEIGHT-2*Abstand);
    return y_svg;
}


int main (){
    
    float laengex,laengey,Zahl,x1,x2,y1,y2,y0,x0,x;
 
    if (Y_MAX<=Y_MIN||X_MAX<=X_MIN){
        printf("Fenstereinstellungen falsch\n");
        return 0;}
    
//Überschrift SVG
    
    Überschrift();
    
    Rechteck(10,10,SVG_WIDTH-5,SVG_HEIGHT-5,"white");
    
//x-Achse
    
    
    laengex=(SVG_HEIGHT-2*Abstand)/(Y_MAX-Y_MIN);
    x1=Abstand;
    x2=SVG_WIDTH-Abstand;
    y1=y2=SVG_HEIGHT-(laengex*-Y_MIN)-Abstand;
    Linie(x1, y1, x2, y2,"black");
    Dreieck(x2,y1,90);
    
    y0=y1;
    
    kLinie(Abstand, Abstand, SVG_WIDTH-Abstand, Abstand);   //damit oben nicht offen
    
    
//y-Achse
    
    laengey=(SVG_WIDTH-2*Abstand)/(X_MAX-X_MIN);
    y1=Abstand;
    y2=SVG_HEIGHT-Abstand;
    x1=x2=(laengey*-X_MIN)+Abstand;
    Linie(x1, y1, x2, y2, "black");
    Dreieck(x1,y1,0);
    x0=x1;
    
    kLinie(Abstand, SVG_HEIGHT-Abstand, SVG_WIDTH-Abstand, SVG_HEIGHT-Abstand);

    
//X-Achsen-Beschriftung
    
    laengex=(SVG_WIDTH-2*Abstand)/(X_MAX-X_MIN);
    x1=Abstand;
    y1=y0+25;
    Zahl=X_MIN;
    
    while (Zahl<=X_MAX){
        
    Zahlen(x1-6, y1, Zahl);
        
    kLinie(x1, Abstand, x1, SVG_HEIGHT-Abstand);
    Linie(x1, y1-20, x1, y1-30, "black");
   
        
        x1=x1+laengex;
    Zahl++;
    }
    

    x1=SVG_WIDTH-Abstand;
    Text(x1+15,y0+4,"x");
    
//Y-Achsen-Beschriftung
    
    laengey=(SVG_HEIGHT-2*Abstand)/(Y_MAX-Y_MIN);
    y1=SVG_HEIGHT-Abstand;
    x1=x0;
    Zahl=Y_MIN;
    
    while (Zahl<=Y_MAX){
        
        Zahlen(x1+15, y1+4, Zahl);
        
        
        kLinie(Abstand, y1, SVG_WIDTH-Abstand, y1);
        Linie(x1-5, y1, x1+5, y1, "black");
        
        y1=y1-laengey;
        Zahl++;
    }
    

    y1=Abstand;
    Text(x0-5,y1-15,"y");

    
  
    
//Graph 1
    
    x1=X_MIN;

    while (x1+GEN<=X_MAX){
        x=x1;
        y1=FUNKTION1;
        x=x1+GEN;
        y2=FUNKTION1;
        
        if (y1<=Y_MAX&&y2<=Y_MAX&&y1>=Y_MIN&&y2>=Y_MIN)
            Linie(x_mat2svg(x1), y_mat2svg(y1), x_mat2svg(x1+GEN), y_mat2svg(y2), "blue");
        
        x1=x1+GEN;
    }

    
//Graph 2
    
    x1=X_MIN;
    
    while (x1+GEN<=X_MAX){
        x=x1;
        y1=FUNKTION2;
        x=x1+GEN;
        y2=FUNKTION2;
        
        if (y1<=Y_MAX&&y2<=Y_MAX&&y1>=Y_MIN&&y2>=Y_MIN)
            Linie(x_mat2svg(x1), y_mat2svg(y1), x_mat2svg(x1+GEN), y_mat2svg(y2), "red");
        
        x1=x1+GEN;
    }
    
    
//Legende
    
    Rechteck(Abstand+10,Abstand+10,Abstand+120,Abstand+70,"white");
    Rechteck(Abstand+20,Abstand+15,Abstand+40,Abstand+35,"blue");
    Text(Abstand+50,Abstand+30,"sin(x)");
    Rechteck(Abstand+20,Abstand+45,Abstand+40,Abstand+65,"red");
    Text(Abstand+50,Abstand+60,"cos(x)");
    
    
    printf("</svg>");

//Zum Testen des Umrechnens
/*
    y1=y_svg2mat(100);
    printf("\n%f\n",y1);
    y1=y_mat2svg(2.42);
    printf("\n%f\n",y1);
    x1=x_svg2mat(500);
    printf("\n%f\n",x1);
    x1=x_mat2svg(10);
    printf("\n%f\n",x1);
    */
    
    return 0;
}
