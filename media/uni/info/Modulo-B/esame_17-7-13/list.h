#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char nome[10];
    char cognome[10];
    int reddito;
}persone;
typedef struct element
{
    persone P;
    struct element *next; 
}item;
typedef item *list;
list insord(persone P, list l);
void printlist(list l);
