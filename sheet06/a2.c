#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>


int BMP_HEIGHT = 1024;
int BMP_WIDTH = 1024;

#define BLACK 0x00000000
#define WHITE 0x00FFFFFF
#define RED   0x00FF0000
#define GREEN 0x0000FF00
#define BLUE  0x000000FF

void write_N_byte(FILE * file, uint64_t byte, int N) {
    for (int i=0;i<N;i++){
        fputc(byte % 256,file);
        byte/=256;
    }

}


void bitmap_file_header(FILE * file) {
  
  write_N_byte(file, 'B', 1);
  write_N_byte(file, 'M', 1);
  write_N_byte(file, 14 + 40 + BMP_WIDTH * BMP_HEIGHT * 32, 4);
  write_N_byte(file, 0, 4);
  write_N_byte(file, 54, 4);
}



void bitmap_info_header(FILE * file) {
  write_N_byte(file, 40, 4);
  write_N_byte(file, BMP_WIDTH, 4);
  write_N_byte(file, -BMP_HEIGHT, 4);
  write_N_byte(file, 1, 2);
  write_N_byte(file, 32, 2);
  write_N_byte(file, 0, 4);
  write_N_byte(file, BMP_WIDTH * BMP_HEIGHT * 32, 4);
  write_N_byte(file, 0, 4);
  write_N_byte(file, 0, 4);
  write_N_byte(file, 0, 4);
  write_N_byte(file, 0, 4);
}

void setPixel(int x, int y, uint32_t color, uint32_t * data) {
    data[y*BMP_WIDTH+x]=color;
    
}

void bmp_rect (uint32_t x, uint32_t y, uint32_t breite, uint32_t höhe,uint32_t colors ,uint32_t * data){
    uint32_t x1=x,y1=y;
    
    for (y=y1; y < y1+höhe; y++) {
        for (x=x1; x < x1+breite; x++) {
            setPixel(x, y, colors, data);
        }
    }
}

void bmp_line(int x1, int x2, int y1, int y2, uint32_t colors, uint32_t *data)
{
    int dx =  abs(x2-x1), sx = x1<x2 ? 1 : -1;
    int dy = -abs(y2-y1), sy = y1<y2 ? 1 : -1;
    int err = dx+dy, e2; /* error value e_xy */
    
    while(1){
        setPixel(x1, y1, colors, data);
        if (x1==x2 && y1==y2) break;
        e2 = 2*err;
        if (e2 > dy) { err += dy; x1 += sx; } /* e_xy+e_x > 0 */
        if (e2 < dx) { err += dx; y1 += sy; } /* e_xy+e_y < 0 */
    }
}

void bmp_triangle(int x1, int x2, int y1, int y2, int z1, int z2, uint32_t colors, uint32_t *data)
{
    

    int a=x1,b=x2,c=y1,d=y2,e=z1,f=z2;
    x1=a,x2=c,y1=b,y2=d;
    int dx =  abs(x2-x1), sx = x1<x2 ? 1 : -1;
    int dy = -abs(y2-y1), sy = y1<y2 ? 1 : -1;
    int err = dx+dy, e2; /* error value e_xy */
    int A[BMP_WIDTH][BMP_HEIGHT];
    
    //Matrix A mit Nullen füllen
    for (int k=0; k<BMP_HEIGHT; k++){
        for (int i=0; i<BMP_WIDTH; i++) {
            A[k][i]=0;
        }
    }
    
// 3 Linienfunktionen für alle Dreieckseiten
//Linien werden als einsen in der Matrix A gespeichert
    
    while(1){
        A[x1][y1]=1;
        if (x1==x2 && y1==y2) break;
        e2 = 2*err;
        if (e2 > dy) { err += dy; x1 += sx; } /* e_xy+e_x > 0 */
        if (e2 < dx) { err += dx; y1 += sy; } /* e_xy+e_y < 0 */
    }
    x1=c,x2=e,y1=d,y2=f;
    dx =  abs(x2-x1), sx = x1<x2 ? 1 : -1;
    dy = -abs(y2-y1), sy = y1<y2 ? 1 : -1;
    err = dx+dy; /* error value e_xy */
    
    while(1){
        A[x1][y1]=1;
        if (x1==x2 && y1==y2) break;
        e2 = 2*err;
        if (e2 > dy) { err += dy; x1 += sx; } /* e_xy+e_x > 0 */
        if (e2 < dx) { err += dx; y1 += sy; } /* e_xy+e_y < 0 */
    }
    x1=e,x2=a,y1=f,y2=b;
    dx =  abs(x2-x1), sx = x1<x2 ? 1 : -1;
    dy = -abs(y2-y1), sy = y1<y2 ? 1 : -1;
    err = dx+dy; /* error value e_xy */
    
    while(1){
        A[x1][y1]=1;
        if (x1==x2 && y1==y2) break;
        e2 = 2*err;
        if (e2 > dy) { err += dy; x1 += sx; } /* e_xy+e_x > 0 */
        if (e2 < dx) { err += dx; y1 += sy; } /* e_xy+e_y < 0 */
    }
    
//Füllung zwischen den Linien
    
    for (int k=0; k<BMP_WIDTH; k++) {
        int i1=0;
        int i2=0;
        for (int i=0; i<BMP_HEIGHT-1; i++) {
            if (A[k][i]==1&&i1==0) {
                i1=i;                       //findet die erste eins in einer Spalte
                }
            if (A[k][i]==1&&A[k][i+1]==0) {
                i2=i;                       //findet die letzte eins in einer Spalte
            }
            for (int j=i1+1; j<i2; j++) {   //ändert nullen zwischen einsen zu zweien
                if (A[k][j]==0) {           //damit der Rand nicht verändert wird
                    A[k][j]=2;
                }
            }
            
        }
    }
    
    
    
    
    
    for (int k=0; k<BMP_HEIGHT; k++){
    for (int i=0; i<BMP_WIDTH; i++) {
        if (A[k][i]==2) {
            setPixel(k, i, colors, data);
        }
        if (A[k][i]==1) {
            setPixel(k, i, BLACK, data);
        }
    }
    }
    
}

void bmp_ellipse(int xm, int ym, int a, int b,uint32_t colors,uint32_t * data)
{
    int dx = 0, dy = b; /* im I. Quadranten von links oben nach rechts unten */
    long a2 = a*a, b2 = b*b;
    long err = b2-(2*b-1)*a2, e2; /* Fehler im 1. Schritt */
    int A[BMP_WIDTH][BMP_HEIGHT];
    
    //Matrix A mit Nullen füllen
    for (int k=0; k<BMP_HEIGHT; k++){
        for (int i=0; i<BMP_WIDTH; i++) {
            A[k][i]=0;
        }
    }
    
    do {
        A[xm+dx][ym+dy]=1;
        A[xm-dx][ym+dy]=1;
        A[xm-dx][ym-dy]=1;
        A[xm+dx][ym-dy]=1;
        
        e2 = 2*err;
        if (e2 <  (2*dx+1)*b2) { dx++; err += (2*dx+1)*b2; }
        if (e2 > -(2*dy-1)*a2) { dy--; err -= (2*dy-1)*a2; }
    } while (dy >= 0);
    
    while (dx++ < a) {
        A[xm+dx][ym]=1; // fehlerhafter Abbruch bei flachen Ellipsen (b=1)
        A[xm-dx][ym]=1; // -> Spitze der Ellipse vollenden
    }
    
    
//Füllung zwischen den Linien
    
    for (int k=0; k<BMP_WIDTH; k++) {
        int i1=0;
        int i2=0;
        for (int i=0; i<BMP_HEIGHT-1; i++) {
            if (A[k][i]==1&&i1==0) {
                i1=i;                           //findet die erste eins in einer Spalte
            }
            if (A[k][i]==1&&A[k][i+1]==0) {
                i2=i;                           //findet die letzte eins in einer Spalte
            }
            for (int j=i1+1; j<i2; j++) {       //ändert nullen zwischen einsen zu zweien
                if (A[k][j]==0) {               //damit der Rand nicht verändert wird
                    A[k][j]=2;
                }
            }
        }
    }
    
    for (int k=0; k<BMP_HEIGHT; k++){
        for (int i=0; i<BMP_WIDTH; i++) {
            if (A[k][i]==2) {
                setPixel(k, i, colors, data);
            }
            if (A[k][i]==1) {
                setPixel(k, i, BLACK, data);
            }
        }
    }
}


int main() {

//  uint32_t colors[] = { BLACK, WHITE, RED, GREEN, BLUE };

  uint32_t *data = NULL;
    data=(uint32_t*)malloc(BMP_WIDTH*BMP_HEIGHT*sizeof(uint32_t));
    
    
    bmp_rect(0, 0, BMP_WIDTH, BMP_HEIGHT, BLACK ,data);
    bmp_rect(5, 5, BMP_WIDTH-10, BMP_HEIGHT-10, WHITE ,data);
    bmp_ellipse(512, 512, 300, 300, GREEN, data);
    bmp_triangle(215,512,812,512,700,278,BLUE,data);
    bmp_line(512,700,512,278,RED,data);
    
  // Schreibe BMP Datei
  FILE *file = fopen("raster.bmp", "w");    //w steht für schreiben     //a steht für anhängen
  bitmap_file_header(file);
  bitmap_info_header(file);
  for (int y = 0; y < BMP_HEIGHT; y++) {
    for (int x = 0; x < BMP_WIDTH; x++) {
      write_N_byte(file, data[y * BMP_WIDTH + x], 4);
    }
  }
  fclose(file);

    free (data);
  return 0;
}
