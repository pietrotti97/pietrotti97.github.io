#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
boolean empty (tree t)
{
    return(t==NULL);
}
tree emptytree(void)
{
    return NULL;
}
tree cons_tree(element e, tree l, tree r)
{
    tree t;
    t=(NODO* ) malloc(sizeof(NODO));
    t->value = e;
    t->left = l;
    t->right=r;
    return (t);
}
element root(tree t)
{
    if(empty(t)) abort();
    else return(t->value);
}
tree left (tree t)
{
    if(empty(t)) return(NULL);
    else return(t->left);
}
tree right ( tree t)
{
	if (empty(t)) return (NULL);
	else return(t->right);
}
void preorder (tree t)
{
    if(t!=NULL)
    {
        printf("%c", t->value);
        preorder(t->left);
        preorder(t->right);
    }
}
void postorder (tree t)
{
    if(t!=NULL)
    {
        postorder(t->left);
        preorder(t->right);
        printf("%c", t->value);
    }
}
void inorder (tree t)
{
    if(t!=NULL)
    {
        inorder (t->left);
        printf("%c",t->value);
        inorder (t->right);
    }
}
boolean member(element e, tree t)
{
    if(empty(t)) return false;
    else
        if(isEqual(e, root(t))) return true;
           else
               return (member(e, left(t)) || member(e, right(t)));
}
int nnodi(tree t)
{
    if(empty(t)) return 0;
    else
        return (1+nnodi(t->left) + nnodi(t->right));
}
int conta_el(element e, tree t)
{
    if(empty (t)) return 0;
    else
        if(isEqual(e, root(t)))
            return (1+conta_el(e, left(t)) + conta_el(e, right(t)));
        else
            return(conta_el(e, left(t)) + conta_el(e, right(t)));
}

