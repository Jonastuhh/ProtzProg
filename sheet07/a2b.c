#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>


#define BMP_HEIGHT 1600
#define BMP_WIDTH 2560

#define n_max 200
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


double mandel(double x1,double y1,double xn, double yn, int n){
    if (n>=n_max) {
        return 0;
    }
    double xn1=xn*xn-yn*yn+x1;  //Realanteil
    double yn1=2*xn*yn+y1;      //Imaginäranteil
    
    int z=xn1*xn1+yn1*yn1;  //Betrag^2 der komplexen Zahl
    
    if (z>=4) {
        return (n);
    }
    n++;
    n=mandel(x1, y1,xn1,yn1,n);
    return n;
}


int main() {

  uint32_t *data = NULL;
    data=(uint32_t*)malloc(BMP_WIDTH*BMP_HEIGHT*sizeof(uint32_t));

    double x1,y1,color,f=1.0;   //x1 Realteil von z, y1 Imaginärteil

    double x_min=0.435396403;
    double x_max=0.451687191;
    double y_min=0.367981352;
    double y_max=0.380210061;
    f=0.3;
    
    /*
    double x_min=-3;
    double x_max=3;
    double y_min=-2;
    double y_max=2;
    */
 
    for (int i=0; i<BMP_HEIGHT; i++) {
        y1=i;
        y1=(y_max-y_min)*y1/BMP_HEIGHT+y_min;
        if (i%(BMP_HEIGHT/100)==0)printf("%.f%%\n",i/(BMP_HEIGHT*0.01)+1);   //Fortschrittsanzeige
        
        for (int j=0; j<BMP_WIDTH; j++) {
            x1=j;
            x1=(x_max-x_min)*x1/BMP_WIDTH+x_min;
            int n=mandel(x1,y1, 0,0,1)*f;
            
            if (n<=20) {
                color=n*12;
            }
            if (n>20) {
                color=0x000FE0FF;
            }
            if (n>50) {
                color=0x0037FFFD;
            }
            if (n>100) {
                color=0x00B7FFFF;
            }
/*
            if (n==0) {
                color=BLACK;
            }
            if (n>0) {
                color=BLUE;
            }
            if (n>10) {
                color=GREEN;
            }
            if (n>30) {
                color=RED;
            }
*/
            data[(BMP_HEIGHT-i-1) * BMP_WIDTH + j]=color;   //-i-1 zum Spiegeln an der x-achse
/*            printf("%d ", data[i * BMP_WIDTH + j]);*/
        }
    }

    
    
    
  FILE *file = fopen("Mandelbrot.bmp", "w");    //w steht für schreiben     //a steht für anhängen
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
