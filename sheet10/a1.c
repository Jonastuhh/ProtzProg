#include <stdio.h>
#include <string.h>

void Tausch(struct st1,struct st2){
	struct *pn;
	*pn=st1->succ;
	st1->succ=st2->succ;
	st2->succ=pn;
}

int main(){
    struct student{
        char vorname[51];
        char nachname[51];
        int matrikelnummer;
        char addresse[101];
        int pflichtkurs;
		struct student *succ;
    };
	struct student1 *pn1;
	pn->vorname="Anna";
	pn->nachname="Musterfrau";
	pn->matrikelnummer=22222;
	pn->addresse="Am Schwarzenberg-Campus 3";
	pn->pflichtkurs=4;
	pn->succ=*pn2;
	
	printf("%10s %15s %7d %35s %4d\n",student1.vorname,student1.nachname,student1.matrikelnummer,student1.addresse,student1.pflichtkurs);
	
	struct student2 *pn2;
	pn->vorname="Hans";
	pn->nachname="Peter";
	pn->matrikelnummer=44444;
	pn->addresse="Kasernenstrasse 12";
	pn->pflichtkurs=2;
	pn->succ=*pn3;
	
	printf("%10s %15s %7d %35s %4d\n",student2.vorname,student2.nachname,student2.matrikelnummer,student2.addresse,student2.pflichtkurs);
	
	struct student3 *pn3;
	pn->vorname="Lisa";
	pn->nachname="Lustig";
	pn->matrikelnummer=66666;
	pn->addresse="Denickestrasse 15";
	pn->pflichtkurs=8;
	pn->succ=NULL;
	
	printf("%10s %15s %7d %35s %4d\n",student3.vorname,student3.nachname,student3.matrikelnummer,student3.addresse,student3.pflichtkurs);
	
	struct student *pn3direkt, *pn4;				//2 zusätzlich hinzufügen
	pn3direkt=*pn2->succ;
	pn4= (struct student*)malloc(sizeof(*pn4));
	pn4->succ=NULL;
	pn3direkt->succ=pn4;
	
	struct student *pn4direkt, *pn5;
	pn4direkt=*pn3->succ;
	pn5= (struct student*)malloc(sizeof(*pn5));
	pn5->succ=NULL;
	pn3direkt->succ=pn5;
	
	*pn2->succ=*pn3direkt->succ;					//3 Liste löschen
	free(pn3direkt);
	
	
return 0;
}
    /*
	struct student student1={"Anna","Musterfrau",22222,"Am Schwarzenberg-Campus 3",4};
    printf("%10s %15s %7d %35s %4d\n",student1.vorname,student1.nachname,student1.matrikelnummer,student1.addresse,student1.pflichtkurs);
    
    struct student student2={"Hans","Peter",44444,"Kasernenstrasse 12",2};
    printf("%10s %15s %7d %35s %4d\n",student2.vorname,student2.nachname,student2.matrikelnummer,student2.addresse,student2.pflichtkurs);
    
    struct student student3={"Lisa","Lustig",66666,"Denickestrasse 15",8};
    printf("%10s %15s %7d %35s %4d\n",student3.vorname,student3.nachname,student3.matrikelnummer,student3.addresse,student3.pflichtkurs);
*/
