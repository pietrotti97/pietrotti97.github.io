#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct elemento
{
	int x, y;
	struct elemento* next;
};
struct elemento* punto;

struct elemento* create_list()
{
	struct elemento *p, *head;
	int n=0, x, y;
	FILE* f;
	f=fopen("punti1.txt", "r");
	if(f == NULL)
	{
		printf("Errore apertura file!");
		return -1;
	}
    p = (struct elemento*)malloc(sizeof(struct elemento));

	while(fscanf(f, "%d %d", &x, &y)==2)
	{
		//printf("%d , %d\n", x, y);
		/*printf("\n");*/
		struct elemento *tmp;
        tmp=(struct elemento*)malloc(sizeof(struct elemento));
		tmp -> x = x;
		tmp -> y = y;
        tmp -> next = NULL;
        if(n==0)
        head = tmp;
        p->next = tmp;
        p = p->next;
		n++;
	}
	return (head);
}
void showlist (struct elemento* head)
{
	printf(" x, y lista -> ");
	while (head!= NULL)
	{
		printf("%d", head->x);
		printf(" , ");
		printf("%d", head->y);
		printf(" -> ");
		head = head->next;
        printf("\n");
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
