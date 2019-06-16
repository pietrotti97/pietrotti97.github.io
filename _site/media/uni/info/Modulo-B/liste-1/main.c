/*
 * main.c
 *
 *  Created on: 22 lug 2017
 *      Author: pietro
 *ciao
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct list_element
{
	int value; //valori della lista
	struct list_element* next;
}item;
typedef item* list;

void showList(list l)
{
	while (l!=NULL)
	{
		printf("%d ", l->value);
		l=l->next;
	}
}
list cons (int e, list l)
{
	list t;
	t=(list) malloc ( sizeof(item));
	t->value=e;
	t->next=l;
	return t;

}
int main()
{
	int i=0;
	list root;
	root = NULL;
	do   									//inserimento in lista
	{
		printf("\nInserire il valore... ");
		scanf ("%d", &i);
		root = cons ( i, root);
	}while(i!=0);
	printf("\nStampa lista\n");
	showList(root);

}

