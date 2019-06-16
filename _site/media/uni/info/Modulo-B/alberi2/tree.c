#include "tree.h"
boolean empty (tree t)
{
    return (t == NULL);
}
boolean emptytree(tree t)
{
    return NULL;
}
element root(tree t)
{
    if(empty(t))
        abort();
    else
        return (t->value);
}
tree left(tree t)
{
    if (empty (t))
        return (NULL);
    else
        return (t->left);
}
tree right(tree t)
{
    if (empty(t))
        return (NULL);
    else
        return (t->right);
}
tree cons_tree(element el, tree l, tree r)
{
    tree t;
    t= (NODO *) malloc(sizeof(NODO));
    t->value=el;
    t->left = l;
    t->right=r;
    return (t);
}
