#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char parola[20];
    int pagina;
}indice;
typedef struct element
{
    indice in_t;
    struct element *left, *right;
}node;
typedef node* tree;
tree reads_files(FILE *v, FILE *i, tree t);
void showlist(tree t);