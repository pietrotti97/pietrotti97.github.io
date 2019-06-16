#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct elemento
{
	int x, y;
	struct elemento* next;
};
struct elemento* punto;



struct elemento* create_list()  //crea la lista inserendo sono gli x>y !!1!1!!
{
	struct elemento *p, *head;
	int n, x, y;
	FILE* f;
	f=fopen("punti1.txt", "r");

	if(f == NULL)
	{
		printf("Errore apertura file!");
		return -1;
	}

	p=(struct elemento*) malloc(sizeof(struct elemento));
	while(fscanf(f, "%d %d", &x, &y)==2)
	{
		if(x>y)
		{
			struct elemento *tmp;
			tmp=(struct elemento*)malloc(sizeof(struct elemento));
			tmp -> x = x;
			tmp -> y = y;
			tmp -> next =NULL;
			if(n==0)
				head=tmp;
			p->next = tmp;
			p=p->next;
			n++;
		}
	}
	return (head);
}
void showlist (struct elemento* head)
{
	struct elemento* read;
	read = (struct elemento*) malloc (sizeof(struct elemento));
	read = head;
	printf(" x, y lista -> ");

	while (read!= NULL)
	{
		printf("%d",read ->x);
		printf(" , ");
		printf("%d",read->y);
		printf(" -> ");
		read = read->next;
	}
	printf("NULL");
}
int main()
{
	struct elemento* L;
	L = create_list();
	showlist(L);
	return 0;
}
