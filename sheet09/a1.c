#include <stdio.h>
#include <string.h>
int main(){
    struct student{
        char vorname[51];
        char nachname[51];
        int matrikelnummer;
        char addresse[101];
        int pflichtkurs;
    };
    struct student student1={"Anna","Musterfrau",22222,"Am Schwarzenberg-Campus 3",4};
    printf("%10s %15s %7d %35s %4d\n",student1.vorname,student1.nachname,student1.matrikelnummer,student1.addresse,student1.pflichtkurs);
    
    struct student student2={"Hans","Peter",44444,"Kasernenstrasse 12",2};
    printf("%10s %15s %7d %35s %4d\n",student2.vorname,student2.nachname,student2.matrikelnummer,student2.addresse,student2.pflichtkurs);
    
    struct student student3={"Lisa","Lustig",66666,"Denickestrasse 15",8};
    printf("%10s %15s %7d %35s %4d\n",student3.vorname,student3.nachname,student3.matrikelnummer,student3.addresse,student3.pflichtkurs);

    struct student swap;
    for (int i=0; i<51; i++) {
           swap.vorname[i]=student1.vorname[i];
    }
 
    for (int i=0; i<51; i++) {
        swap.nachname[i]=student1.nachname[i];
    }

        swap.matrikelnummer=student1.matrikelnummer;
    

    for (int i=0; i<101; i++) {
        swap.addresse[i]=student1.addresse[i];
    }
        swap.pflichtkurs=student1.pflichtkurs;

    
    
    for (int i=0; i<51; i++) {
        student1.vorname[i]=student3.vorname[i];
    }
    
    for (int i=0; i<51; i++) {
        student1.nachname[i]=student3.nachname[i];
    }
    
    student1.matrikelnummer=student3.matrikelnummer;
    
    
    for (int i=0; i<101; i++) {
        student1.addresse[i]=student3.addresse[i];
    }
    student1.pflichtkurs=student3.pflichtkurs;
    
    
    
    
    for (int i=0; i<51; i++) {
        student3.vorname[i]=swap.vorname[i];
    }
    
    for (int i=0; i<51; i++) {
        student3.nachname[i]=swap.nachname[i];
    }
    
    student3.matrikelnummer=swap.matrikelnummer;
    
    
    for (int i=0; i<101; i++) {
        student3.addresse[i]=swap.addresse[i];
    }
    student3.pflichtkurs=swap.pflichtkurs;
    

    printf("\n%10s %15s %7d %35s %4d\n",student1.vorname,student1.nachname,student1.matrikelnummer,student1.addresse,student1.pflichtkurs);
    printf("%10s %15s %7d %35s %4d\n",student2.vorname,student2.nachname,student2.matrikelnummer,student2.addresse,student2.pflichtkurs);
    printf("%10s %15s %7d %35s %4d\n\n",student3.vorname,student3.nachname,student3.matrikelnummer,student3.addresse,student3.pflichtkurs);
    return 0;
}
