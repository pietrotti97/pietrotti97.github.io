#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dim 20

typedef struct albero
{
	char parola[dim];
	struct albero *left,*right;
} nodo;

typedef nodo *tree;

tree funzioneA (FILE *f1, FILE *f2, tree t);

tree inserimento (char par[],tree t);

tree allocazione (char par[], tree l, tree r);

void funzioneB (tree t);

int funzioneC (tree t);