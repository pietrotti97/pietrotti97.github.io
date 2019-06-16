#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct element
{
    char P[20];
    struct element *left, *right;
}nodo;
typedef nodo *tree;
tree reads_files(FILE *p1,FILE *p2,tree t);
void printree(tree t);
int nnodes(tree t);