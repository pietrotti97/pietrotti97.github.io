#include "el.h"
typedef struct nodo
{
    element value;
    struct nodo *left, *right;
}NODO;

typedef NODO* tree;
boolean empty(tree);
tree emptytree(void);
element root(tree);
tree left(tree);
tree right(tree);
tree cons_tree(element, tree, tree);

void preorder(tree);
void inorder(tree);
void postorder(tree);
boolean member (element , tree );
int nnodi(tree);
int conta_el(element e, tree t);
