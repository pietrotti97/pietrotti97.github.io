#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct element
{
    char parola[20];
    struct element *left, *right;
}nodo;
typedef nodo* tree; 
tree insord(char C[], tree t);
void showlist (tree t);