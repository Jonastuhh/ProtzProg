#include <stdio.h>

int main(){
	int n=7,m,o,a,y;	// n Zahl zum Eingeben ; m Zahl für die Leerzeichen wird runtergzählt ;o ist m nur fest ; a ist 2n zum anzeigen der Zahlen an der Y Achse; y benutzen wir um jede 2 Zeile den Y Wert auszugeben
	o=3*n+1;
	m=o;
	a=2*n;
	y=n;
	do{				// y ausgeben	
	printf(" ");
	m=m-1;
	}while(m>=0);
	printf("y\n");
	m=o;
	do{				// ^ ausgeben
	printf(" ");
	m=m-1;
	}while(m>=0);
	printf("^\n");
	m=o+1;
	while(a>2*-n-2){	// Achse
		
		while(m>0){
		printf(" ");
		m=m-1;
		};
		printf("|");
		if (a%2==0) {
            printf(" %d",y);
            y=y-1;
        }
        
        a=a-1;
        printf("\n");
	m=o+1; 
	}
return 0;
}
