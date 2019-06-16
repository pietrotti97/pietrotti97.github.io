#include "funzioni.h"

main ()
{
	FILE *f1,*f2;
	tree t=NULL;

	f1=fopen("parole1.txt","rt");
	if (f1==NULL)
	{
		system ("cls");
		printf ("Errore apertura file 1\n");
		exit(-1);
	}
	f2=fopen("parole2.txt","rt");
	if (f2==NULL)
	{
		system ("cls");
		printf ("Errore apertura file 2\n");
		exit(-1);
	}

	t=funzioneA(f1,f2,t);

	printf("STAMPA DELL'ALBERO:\n");
	printf("\n");
	funzioneB(t);

	printf("\n");
	printf ("L'altezza dell'albero vale %d\n",funzioneC(t));
}