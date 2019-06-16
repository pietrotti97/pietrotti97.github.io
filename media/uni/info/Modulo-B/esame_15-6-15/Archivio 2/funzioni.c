#include "funzioni.h"

int funzioneC (tree t)
{
	if ((t==NULL)||(t->left==NULL&&t->right==NULL)) return 0;					//uso la seconda condizione per saltare il conto dell'ultimo nodo, in modo da avere l'altezza e non il numero dei nodi
	else
		if (funzioneC(t->left)>funzioneC(t->right)) return 1+funzioneC(t->left);
		else return 1+funzioneC(t->right);
}

void funzioneB (tree t)
{
	if (t!=NULL)
	{
		funzioneB(t->left);
		printf("%s\n",t->parola);
		funzioneB(t->right);
	}
}

tree allocazione (char par[], tree l, tree r)
{
	tree t;
	t=(tree)malloc(sizeof(nodo));
	strcpy(t->parola,par);
	t->left=l;
	t->right=r;
	return t;
}

tree inserimento (char par[], tree t)
{
	if (t==NULL) return allocazione(par,NULL,NULL);
	else
		if (strcmp(par,t->parola)>0) t->right=inserimento(par,t->right);
		else t->left=inserimento(par,t->left);
	return t;
}

tree funzioneA (FILE *f1, FILE *f2, tree t)
{
	char par[dim],par2[dim];
	int trov=0;

	while (fscanf(f1,"%s",par)>0)
	{
		while ((fscanf(f2,"%s",par2)>0)&&(trov==0))
		{
			if (strcmp(par,par2)==0) trov=1;
		}
		if (trov==0) t=inserimento(par,t);
		trov=0;
		rewind(f2);
	}
	fclose(f1);
	fclose(f2);
	return t;
}