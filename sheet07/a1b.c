#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>


int BMP_HEIGHT = 11;
int BMP_WIDTH = 11;

#define BLACK 0x00000000
#define WHITE 0x00FFFFFF
#define RED   0x00FF0000
#define GREEN 0x0000FF00
#define BLUE  0x000000FF
#define YELLOW 0x00FFFF00
#define GRAU 0x00888888
#define M 11

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

void Weg (int x1, int y1, int x2, int y2,int *B){
    
    for (int i=x1-1; i<x2; i++) {
        for (int k=y1-1; k<y2; k++) {
            B[i*M+k]=1;
        }}
    
}



int maus (int x, int y,int *B){
    int a=0;
    B[(x)*M+(y)]=3;
    if (x==0||y==0||x==M-1||y==M-1) {
        a=1;
    }
    if (a==1) {
        return 1;
    }
    
    if (B[x*M+y-1]==1) {
        B[(x)*M+(y)]=2;
        a=maus(x,y-1,B);
        if (a==1) {
            return 1;
        }
        
    }
    if (B[(x+1)*M+y]==1) {
        B[(x)*M+(y)]=2;
        a=maus(x+1,y,B);
        
        if (a==1) {
            return 1;
        }
    }
    if (B[(x)*M+(y+1)]==1) {
        B[(x)*M+(y)]=2;
        a=maus(x,y+1,B);
        if (a==1) {
            return 1;
        }
    }
    if (B[(x-1)*M+(y)]==1) {
        B[(x)*M+(y)]=2;
        a=maus(x-1,y,B);
        if (a==1) {
            return 1;
        }
    }
    B[(x)*M+(y)]=4;
    return 0;
}

int main() {

//  uint32_t colors[] = { BLACK, WHITE, RED, GREEN, BLUE };

  uint32_t *data = NULL;
    data=(uint32_t*)malloc(BMP_WIDTH*BMP_HEIGHT*sizeof(uint32_t));
    
    int B[M*M];
    int x,y;
    //Wand(*) ist 0
    for (int k=0; k<M; k++) {
        for (int i=0; i<M; i++) {
            B[i*M+k]=0;
        }}
    
    
    Weg(1, 10, 2, 10,B);
    Weg(2, 6, 2, 10,B);
    Weg(2, 3, 2, 4,B);
    Weg(3, 4, 3, 6,B);
    Weg(3, 2, 5, 2,B);
    Weg(4, 6, 4, 7,B);
    Weg(5, 2, 5, 6,B);
    Weg(4, 10, 10, 10,B);
    B[3*11+8]=1;
    Weg(5, 8, 8, 8,B);
    B[5*11+8]=1;
    Weg(6, 5, 6, 6,B);
    B[5*11+2]=1;
    Weg(7, 2, 7, 4,B);
    Weg(8, 4, 8, 8,B);
    Weg(9, 2, 9, 3,B);
    Weg(10, 2, 10, 9,B);
    B[9*11+5]=0;
    B[8*11+4]=1;
    B[10*11+6]=1;
    
    /*
     Maze runner
     B[9]=0;
     B[10*11+6]=0;*/
    int a,b=0;
    printf("Mauskoordinaten x y:\n");
    scanf(" %d %d",&x,&y);
    x=x-1;y=y-1;
    if (x<0||y<0||x>M-1||y>M-1) {
        printf("Maus rennt frei durch die Gegend\n");
        b=1;
    }
    
    if (B[(x)*M+(y)]==0&&b!=1) {
        printf("Maus erstickt in Mauer\n");
        B[(x)*M+(y)]=5;
        }
    else{
        a=maus(x,y,B);
    
    
    if (a==0&&b!=1) {
        printf("Maus verhungert\n");
    }
    for (int k=0; k<M; k++) {
        printf("\n");
        for (int i=0; i<M; i++) {
            printf("%d ",B[i*M+k]);
        }}
    
    if (a==1) {
        printf("\n\nAusgang gefunden\n\n");
    }
    }
    for (int y = 0; y < BMP_HEIGHT; y++) {
        for (int x = 0; x < BMP_WIDTH; x++) {
            if (B[y*M+x]==1) {
                B[y*M+x]=WHITE;
            }
            if (B[y*M+x]==2) {
                B[y*M+x]=YELLOW;
            }
            if (B[y*M+x]==3) {
                B[y*M+x]=GRAU;
            }
            if (B[y*M+x]==4) {
                B[y*M+x]=WHITE;
            }
            if (B[y*M+x]==5) {
                B[y*M+x]=RED;
            }
        }

    }
    
    for (int y = 0; y < BMP_HEIGHT; y++) {
        for (int x = 0; x < BMP_WIDTH; x++) {
            data[y*BMP_WIDTH+x]=B[x*M+y];
        }
    }
    
    
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
