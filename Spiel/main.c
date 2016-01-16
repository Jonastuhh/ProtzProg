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
#include <ncurses.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define WAND 999
#define ESSENPOS -1
#define ANZEIGEDAUER 3000000


int Width=10,Height=10;
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
    if (Richtun=='s') Kopf=Kopf+1;
    if (Richtun=='d') Kopf=Kopf+Width;
    if (Richtun=='a') Kopf=Kopf-Width;
    if (Richtun=='w') Kopf=Kopf-1;
    
    
}


int main(){
    int Existenzessen;
    int Highscore=0;
    initscr();
    noecho();
    char Auswahl=0;
    while (Auswahl!='q') {              //Auswahlmenue
        clear();
        printw("Auswahlmenue:\n");
        printw("w) Spiel starten\n");
        printw("a) Spielfeldgroesse einstellen\n");
        printw("s) Highscoresss\n");
        printw("q) Spiel beenden\n");
        
        Auswahl=getch();
    
    
    
    
    
    
    
    int Feld[Width*Height];
    int Feldanzeigen[Width*Height];
    for (int i=0; i<Height; i++) {
        for (int k=0; k<Width; k++) {
            Feld[k+i*Width]=0;
            Feldanzeigen[k+i*Width]=0;
        }
    }
        if (Auswahl=='s'){
            clear();
            printw("Highscore: %d\n",Highscore);
            getch();
        }
        
        if (Auswahl=='a'){
            clear();
            printw("Spielfeldgroesse eingeben: ");
            scanw("%d %d", &Width, &Height);

        }
        
        if (Auswahl=='w'){
            int Schlangenlaenge=1;
            clear();

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
            
            Feld[Kopf]=0;
            int c='u';
            int Key;
            

        while (1){
        
        Existenzessen=0;
        
        for (int i=0; i<(Height*Width); i++) {							//gibt es bereits Essen auf dem spielfeld
            if (Feld[i]!=ESSENPOS) Existenzessen++;
        }
        
        if (Existenzessen==(Height*Width)) {							//falls es kein essen gibt essenverteilung aufrufen
            int Essenpos=Essen(Feld);
            Feld[Essenpos]=ESSENPOS;
            Schlangenlaenge++;
        }
        
        
        for (int i=1; i<Height-1; i++) {
            for (int k=1; k<Width-1; k++) {
                if (Feld[k+i*Width]>=1&&Feld[k+i*Width]<=900) Feld[k+i*Width]--;
                
            }
        }
        timeout(100);
         c= getch();
        
        if (c=='w'||c=='s'||c=='a'||c=='d')  Key=c;
        Richtung(Key);
        if (Feld[Kopf]>0&&Feld[Kopf]<=WAND) {
            Highscore=Schlangenlaenge-2;
            break;
            
        }
        Feld[Kopf]=Schlangenlaenge;
        
        
        
        //Visualisierung:
        
        for (int i=0; i<Height; i++) {
            for (int k=0; k<Width; k++) {
                if (Feld[k+i*Width]==WAND) Feldanzeigen[k+i*Width]='#';
                if (Feld[k+i*Width]==0) Feldanzeigen[k+i*Width]=' ';
                if (Feld[k+i*Width]==ESSENPOS) Feldanzeigen[k+i*Width]='o';
                if (Feld[k+i*Width]==Schlangenlaenge) Feldanzeigen[k+i*Width]='@';
                if (Feld[k+i*Width]>0&&Feld[k+i*Width]<Schlangenlaenge) Feldanzeigen[k+i*Width]='*';
                
                
            }
        }
        
        
        for (int i=0; i<Height; i++) {
            for (int k=0; k<Width; k++) {
                if (Feld[k+i*Width]==WAND) mvaddch(k,i,'#');
                if (Feld[k+i*Width]==0) mvaddch(k,i,' ');
                if (Feld[k+i*Width]==ESSENPOS) mvaddch(k,i,'o');
                if (Feld[k+i*Width]==Schlangenlaenge) mvaddch(k,i,'@');
                if (Feld[k+i*Width]>0&&Feld[k+i*Width]<Schlangenlaenge) mvaddch(k,i,'*');
            }
        }}
    }}
    return 0;
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
 mvaddch(y, x, "o");
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
