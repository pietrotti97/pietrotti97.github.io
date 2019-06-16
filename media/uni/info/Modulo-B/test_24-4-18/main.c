#include "list.h"
int main()
{
	FILE *a;
	element el;
	list root =  NULL;
	a = fopen("alimenti.bin", "rb");
	if (a == NULL)
	{
		printf("Errore nell'apertura del file alimenti.bin");
		exit(1);
	}
	while (fread(&el, sizeof(element), 1, a) !=0)
	{
            //printf("%s %d\n", el.nome, el.kcal);
            root = insord(root, el);
	}
	fclose(a);
	showlist(root);
    return 0;
}
