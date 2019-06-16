#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
boolean empty(tree t)
{
    return (t==NULL);
}
tree emptytree(void)
{
    return (NULL);
}
element root(tree t)
{
    if(empty(t))
        abort();
    else
        return t->value;
}
tree left(tree t) //restituisce t->left o NULL
{
    if(t->left == NULL)
        return (NULL);
    else
        return t->left;
}
tree right(tree t)
{
    if(t->right = NULL)
        return (NULL);
    else
        return t->right;
}
tree constree(element a, tree l, tree r)
{
    tree t;
    t=(tree) malloc (sizeof (nodo));
    t->value=a;
    t->left = l;
    t->right = r;
    return t;
}