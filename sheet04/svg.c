#include <stdio.h>

int main() {
	int n=5,x1,x2,y1,y2,g,k ;  // n gibt man ein, g gesammt größe ; k zum zählen
	
	g=n*20+20;
	
	printf("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");		// größe des Fensters
	printf("<svg xmlns=\"http://www.w3.org/2000/svg\"\n");
	printf("     xmlns:xlink=\"http://www.w3.org/1999/xlink\"\n");
	printf("     xmlns:ev=\"http://www.w3.org/2001/xml-events\"\n");
	printf("     version=\"1.1\"\n");
	printf("     baseProfile=\"full\"\n");
	printf("     width=\"%d\"\n",g);
	printf("     height=\"%d\">\n\n",g);
	
	x1=x2=n*10+10;				// koordinaten für y-Achse
	y1=10;
	y2=n*20+20;
	
	printf("<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\" \
  stroke-width=\"4\" />\n", x1, y1, x2, y2);		// Y-achse
  
	printf("<text x=\"%d\" y=\"%d\" font-size=\"50\">^</text>\n",x1,y1);	//^
	
	y1=5;
	
	printf("<text x=\"%d\" y=\"%d\" font-size=\"50\">y</text>\n",x1,y1);	// y
	
	x1=10;
	x2=n*20+20;
	y1=y2=n*10+10;
	
	printf("<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\" \
  stroke-width=\"4\" />\n", x1, y1, x2, y2);	//X-Achse
  
	printf("<text x=\"%d\" y=\"%d\" font-size=\"50\">></text>\n",x1,y1); // >
	
	x1=5;
	
	printf("<text x=\"%d\" y=\"%d\" font-size=\"50\">x</text>\n",x1,y1); // x
	
	x1=n*10;
	y1=n*20;
	k=-n;
	
	while(k<=n){
		if(k){			// nicht bei k = 0
		printf("<text x=\"%d\" y=\"%d\" font-size=\"50\">%d</text>\n",x1,y1,k);
		}
		k=k++;
		y1=y1-10;
	}
	x1=n*20;
	y1=n*10+30;
	k=-n
	while(k<=n){
		if(k){			// nicht bei k = 0
		printf("<text x=\"%d\" y=\"%d\" font-size=\"50\">%d</text>\n",x1,y1,k);
		}
		k=k++;
		x1=x1-10;
	}
	
	return 0;
}
