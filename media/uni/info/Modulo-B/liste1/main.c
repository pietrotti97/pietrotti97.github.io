#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct elemento
{
	int inf;
	struct elemento* pun;
};
struct elemento* lista;
struct elemento *crealista()
{
	struct elemento *p, *punt;
	int i, n;
	printf("/nSpecificare num elementi...");
	scanf("%d", &n);
	if(n==0)
	{
		p=NULL;
	}
	else
	{
		p=(struct elemento* ) malloc(sizeof(struct elemento));
		printf("\nInserisci il primo valore...");
		scanf("%d", & p->inf);
		punt = p;
	
		for(i=2;i<=n;i++)
		{
			punt -> pun=(struct elemento* )malloc(sizeof(struct elemento));
			punt = punt->pun;
			printf("\nInserisci il %d elemento...", i);
			scanf("%d", &punt ->inf);
		}
		punt ->pun= NULL;
	}
	return (p);
}
void showlist(struct elemento* p)
{
	printf("n lista->");
	while(p!=NULL)
	{
		printf("%d", p->inf);
		printf("->");
		p= p->pun;
	}
	printf("NULL");
}
int main()
{
	struct elemento* lista;
	lista= crealista();
	showlist(lista);
	return 0;
}
