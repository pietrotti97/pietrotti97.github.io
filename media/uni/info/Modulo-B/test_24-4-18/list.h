#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	char nome[50];
	int kcal;
}element;
typedef struct list_element
{
	element value;
	struct list_element *next;
}NODO;
typedef NODO *list;
list insord(list l, element el);
void showlist(list l);