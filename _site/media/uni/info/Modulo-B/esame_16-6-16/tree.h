#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char prodotto[50];
    int scatole;
}prodotti;
typedef struct element
{
    prodotti P;
    struct element *left, *right;
}nodo;
typedef nodo *tree;
tree insord (prodotti PRO, tree t);
void printree(tree t);
int findel(prodotti PRO, tree t);