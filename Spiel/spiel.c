/*

Snake:
 
-Auswahlmenü: Abfrage von Schwierigkeitsgrad, Spielfeldgröße (und Hindernisse/Spieleranzahl), Starten, Beenden
-Schlange steuerbar
-Schlangengröße konstant, solange nicht gegessen wird
-Essen wird zufällig verteilt
-Schlange wird beim Essen größer
-grafisch im Terminal darstellen
-Geschwindigkeit der Schlange variabel (Schwierigkeit)
-variable Spielfeldgröße
-Highscore
-Rand und Selbstüberschneidung führt zu Spielende
(-zufällige Hindernisse ab bestimmten Schwierigkeitsgrad)
(-Zwei Spieler)

 Design:
 
 Programmstruktur:
 -Startbedingungen werden abgefragt (Auswahlmenü)
 -Spiel wird gestartet
 -Highscore wird nach Spielende gespeichert
 -Auswahlmenü wird angezeigt (Anfang)
 
 Funktionen:
 -Richtungsfunktion
 -Essensverteilung
 -Highscorefunktion (Abspeichern)
 
 Datentypen:
 -int für Programm
 -char für Grafik
 
 Codestil:
 -ausführlich
 
 http://www.gnu.org/software/ncurses/
 
 */



#include <stdio.h>
//#include <ncurses.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define WAND 999
#define ESSENPOS 998


int Width=4,Height=4;
int Kopf;

int Essen (int *Feld){
    int Essenpos=0;
    while (1) {
        
        
        Essenpos=clock()%(Width*Height);
        if (Feld[Essenpos]==0) {
            break;
        }
    }
    return Essenpos;

    
}

void Richtung(int Richtun ){
    if (Richtun=='d') Kopf=Kopf+1;
    if (Richtun=='s') Kopf=Kopf+Width;
    if (Richtun=='w') Kopf=Kopf-Width;
    if (Richtun=='a') Kopf=Kopf-1;


}


int main(){
    int Schlangenlaenge=1;
	int Existenzessen;
	int Highscore=-1;
	int End;								//nur damit fester nicht sofort geschlossen wird
    

   int Feld[Width*Height];
    for (int i=0; i<Height; i++) {
        for (int k=0; k<Width; k++) {
            Feld[k+i*Width]=0;
        }
    }
    int Feldanzeigen[Width*Height];
    for (int i=0; i<Height; i++) {
        for (int k=0; k<Width; k++) {
            Feldanzeigen[k+i*Width]=0;
        }
    }
    
    Kopf=(Height/2-1)*Width+Width/2-1;

    Feld[Kopf]=Schlangenlaenge;
        for (int k=0; k<Width; k++) {
            int i=0;
            Feld[k+i*Width]=WAND;
        }
    
        for (int k=0; k<Width; k++) {
            int i=Height-1;
            Feld[k+i*Width]=WAND;
        }
    
        for (int i=0; i<Height; i++) {
            int k=0;
            Feld[k+i*Width]=WAND;
        }
    
        for (int i=0; i<Height; i++) {
            int k=Width-1;
            Feld[k+i*Width]=WAND;
        }
		
    while (1){
      
	 Existenzessen=0;
	 
	 for (int i=0; i<(Height*Width); i++) {							//gibt es bereits Essen auf dem spielfeld
            if (Feld[i]!=ESSENPOS) Existenzessen++;
    }
	
	if (Existenzessen==(Height*Width)) {							//falls es kein essen gibt essenverteilung aufrufen
		int Essenpos=Essen(Feld);
		Feld[Essenpos]=ESSENPOS;
		Highscore++;
	}
    
	
    for (int i=1; i<Height-1; i++) {
        for (int k=1; k<Width-1; k++) {
            if (Feld[k+i*Width]>=1&&Feld[k+i*Width]<=900) Feld[k+i*Width]--;
            
        }
    }
       // usleep(300000);
       int Key= getchar();
    Richtung(Key);
    Feld[Kopf]=Schlangenlaenge;
        
        if (Kopf%Width==0) {
            break;
        }
    
//Visualisierung:
    
    for (int i=0; i<Height; i++) {
        for (int k=0; k<Width; k++) {
            if (Feld[k+i*Width]==WAND) Feldanzeigen[k+i*Width]='#';
            if (Feld[k+i*Width]==0) Feldanzeigen[k+i*Width]=' ';
            if (Feld[k+i*Width]==ESSENPOS) Feldanzeigen[k+i*Width]='o';
            if (Feld[k+i*Width]==Schlangenlaenge) Feldanzeigen[k+i*Width]='@';


        }
    }

    
    for (int i=0; i<Height; i++) {
        printf("\n");
        for (int k=0; k<Width; k++) {
            printf("%c",Feldanzeigen[Width*i+k]);
        }
    }
    printf("\n");
}
printf("Dein score ist:%d \n Lies etwas ein um das Spiel zu beenden",Highscore); 
scanf("%d",&End);											//Fenster wird nicht sofort geschlossen 
 }
 /*
#include <ncurses.h>
#include <unistd.h>
#define DELAY 30000
int main(int argc, char *argv[]) {
    int x = 0, y = 0;
    int max_y = 0, max_x = 0;
    int next_x = 0;
    int direction = 1;
    initscr();
    noecho();
    curs_set(FALSE);
    // Global var `stdscr` is created by the call to `initscr()`
    getmaxyx(stdscr, max_y, max_x);
    while(1) {
        clear();
        mvprintw(y, x, "o");
        refresh();
        usleep(DELAY);
        next_x = x + direction;
        if (next_x >= max_x || next_x < 0) {
            direction*= -1;
        } else {
            x+= direction;
        }
    }
    endwin();
}*/
