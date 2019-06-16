#include <stdio.h>
#include <stdlib.h>
typedef struct list_element
{
	int value;
	struct list_element *next;
}item;
typedef item *list;
int ins_list(list L, list *root)
{
	int i;
	do
	{
		printf("Inserire il valore: \t");
		scanf ("%d", &i);
		L = (list) malloc (sizeof ( item));
		L->value = i;
		L-> next = *root;
		*root = L;
	}while (i!=0);
	return 0;
}
int ins_tail(list L, list *root, int n)
{
	int i;
	L=(list) malloc (sizeof (item));
	L->value=n;
	L->next=*root;
	*root = L;
	return 0;
}
void print_list(list L, list *root)
{
	int n=0;
	L = *root;
	do
	{
		printf("Il valore:\t%d\n",L->value);
		L =L->next;
	}while (L != NULL);
}
int main()
{
	list L;
	int n;
	list root= NULL;
	if(ins_list(L, &root)==0)
		printf("Inserimento terminato!");
	print_list(L, &root);
	printf("Inserisci un elemento in coda alla lista:\t");
	scanf("%d", &n);
	if(	ins_tail(L, &root, n)==0)
			printf("ok!\n");
	print_list(L, &root);
	return 0;
}
