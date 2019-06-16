#include "element.h"
typedef struct nodo 
{
    element value;
    struct nodo *left, *right;
}NODO;
typedef NODO *tree;

boolean empty ( tree t);
tree empty(void);
element root(tree t);
tree left ( tree t);
tree right ( tree t);
tree cons_tree(element el, tree l, tree r);
