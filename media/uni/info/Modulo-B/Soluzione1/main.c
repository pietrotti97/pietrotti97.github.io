#include <stdio.h>
#include <stdlib.h>
#define IPER 300
#define DIM 50

typedef struct {
	char nome[DIM];
	int val;
}element;

typedef struct nodo {
	element value;
	struct nodo *next;
}NODO;

typedef NODO *list;




int isless(element a, element b)
{
	if (strcmp(a.nome, b.nome) > 0)
		return 0;
	else
		return 1;
}

void printel(element x)
{
	printf("%s, %d\n", x.nome, x.val);
}

list cons(element el, list l)
{
	list aux = (NODO*)malloc(sizeof(NODO));
	aux->value = el;
	aux->next = l;
	return aux;
}

list insord(element el, list l)
{
	if (l == NULL)
		return cons(el, l);
	else
	{
		if (isless(el, l->value))
			return cons(el, l);
		else
			l->next = insord(el, l->next);
		return l;
	}
}


list funzioneA(FILE *f, list L)
{
	element el;
	while (fread(&el, sizeof(element), 1, f) > 0)
	{
		L = insord(el, L);
	}
	return L;
}

void funzioneC(FILE *output, list L)
{
	static int tot=0;
	if (L != NULL)
	{
		if (L->value.val > IPER)
		{
			fprintf(output, "%s %d\n", L->value.nome, L->value.val);
			tot++;
		}
		funzioneC(output, L->next);
	}
	else
	{
		fprintf(output, "Numero di alimenti ipercalorici: %d\n", tot);
	}
}


void showlist(list l)
{
	if (l != NULL)
	{
		printel(l->value);
		showlist(l->next);
	}
}

main()
{
	list L = NULL;
	FILE *f, *output;

	f = fopen("alimenti.bin", "rb");

	if (f == NULL)
	{
		printf("Non aperto.\n");
		exit(-1);
	}

	L = funzioneA(f, L);

	fclose(f);

	showlist(L);

	output = fopen("output.txt", "wt");

	if (output == NULL)
	{
		printf("File non creato.\n");
		exit(-1);
	}

	funzioneC(output, L);
	fclose(output);
}
