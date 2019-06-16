#include <stdio.h>
#include <stdlib.h>
#include "element.h"

typedef struct nodo
{
    element value;
    struct nodo *left, *right;
}NODO;
typedef NODO *tree;

boolean empty(tree t);
tree emptytree(void);
element root(tree t);
tree left(tree t);
tree right(tree t);
tree constree(element a, tree l, tree r);
