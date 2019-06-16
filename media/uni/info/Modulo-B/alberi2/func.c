#include "func.h"
#include "tree.h"
tree ordins(element el, tree t)
{
    if (t ==NULL)
        return (cons_tree(el, NULL, NULL));
    else
    {
        if (el <= t->value)
            t->left = ordins(el, t->left);
        else
            t->right = ordins(el, t->right);
        return t;
    }
}
void preorder(tree t)
{
    if (t !=NULL)
    {
        printf("%c", t->value);
        preorder (t->left);
        preorder (t->right);
    }
}
void postorder (tree t)
{
    if (t!=NULL)
    {
        postorder(t->left);
        postorder(t->right);
        printf("%d", t->value);
    }
}
void inorder (tree t)
{
    if (t !=NULL)
    {
        inorder (t->left);
        printf("%c", t->value);
        inorder (t->right);
    }
}
boolean member(element el, tree t)
{
    if ( t==NULL)
        return false;
    else
    {
        if (el == t->value)
            return true;
        else
            if (el <t->value)
                return member(el, t->left);
            else
                return member (el, t->right);
    }
}
int max(int a, int b)
{
    if(a >b)
        return a;
    else
        return b;
}
int height_aux(tree t)
{
    if(empty(t))
        return 0;
    else
        return (1+max(height_aux(left (t), height_aux(right(t)))));
}
int height(tree t)
{
    if (empty(t))
        return 0;
    else
        return ( max(height_aux(left (t)), height_aux(right(t))));
}
int n_nodes(tree t)
{
    if(empty(t))
        return 0;
    else
        return(1+ n_nodes(left(t))+n_nodes(right(t)));
}
int balance (tree t)
{
    if(empty(t))
        return 0;
    else
        return (height(left(t))-height(right(t)));
}