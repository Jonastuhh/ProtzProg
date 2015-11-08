/**
 * Prozedurale Programmierung WS 15/16
 *
 * Hallo Tutor als SVG-Grafik
 */

#include <stdio.h>

int main() {
  printf("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
  printf("<svg xmlns=\"http://www.w3.org/2000/svg\"\n");
  printf("     xmlns:xlink=\"http://www.w3.org/1999/xlink\"\n");
  printf("     xmlns:ev=\"http://www.w3.org/2001/xml-events\"\n");
  printf("     version=\"1.1\"\n");
  printf("     baseProfile=\"full\"\n");
  printf("     width=\"500\"\n");
  printf("     height=\"500\">\n\n");

  printf("<rect width=\"500\" height=\"500\" stroke=\"black\" \
  stroke-width=\"10\" fill=\"yellow\" />\n");
  printf("<text x=\"100\" y=\"100\" font-size=\"50\">Hallo</text>\n");
  printf("<text x=\"250\" y=\"110\" font-size=\"70\" fill=\"red\" \
  transform=\"rotate(30 250 110)\">Tutor!</text>\n");

  int x1 = 20, x2 = 480, y = 250;
  printf("<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\" \
  stroke-width=\"4\" />\n", x1, y, x2, y);
    

    
    
    
    
    
    int j=220,k=10,l=140;       //zahlen
    do {
        
    printf("<text x=\"%d\" y=\"%d\" font-size=\"20\" fill=\"orange\">%d</text>  \n",j,l,k);
        j=j-20;
        k=k-1;
        l=l+10;
    } while (k>0);
    
    j=20;k=480;l=250;
    do {                        //linien
        j=j+10;
        l=l-5;
        k=k-10;
     
    
    printf("<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"orange\" \
           stroke-width=\"5\" />\n",j,l,k,l);
    } while (j!=250);
    
    int m=0;                    //kreisel
    while (m!=360) {
        m=m+10 ;
        
        printf("<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"#CD6600\" \
               stroke-width=\"3 \" transform=\"rotate(%d 250 200)\" />\n",220,170,240,190,m);
    }

   do{
	  x1=x1+5;
	  x2=x2-10;
	  y=y+5;
	  y2=y2+5;
	  a=a-1;
	  printf("<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"white\" \
  stroke-width=\"5\" />\n", x1, y, x2, y2);
  } while (a>0);
    
    
    
    
    
    
    
  printf("</svg>\n");

  return 0;
}
