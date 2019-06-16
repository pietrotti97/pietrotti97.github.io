#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "tree.h"

tree ord_ins(element el, tree t)
{
    tree p = NULL, t = root;
    if ( root ==  NULL)
        return constree(el, NULL, NULL);
    else
    {
        while (t !=NULL)
            if( el <= t->value)
            {
                p = t;
                t=t->left;   
            }
            else
            {
                p = t;
                t = ->right;
            }
    }
    if ( el <= p->value)
        p-> left = constree (el, NULL, NULL);
    else
        p->right= constree(el, NULL, NULL);
    return root;
    
}
void preorder (tree t)
{
    if(t !=NULL)
    {
        printf("%d", t->value);
        preorder(t->left);
        preorder(t->right);
    }
}
void postorder(tree t)
{  
    if(t !=NULL)
    {
        postorder(t->left);
        postorder(t->right);
        printf("%d", t->value);
    }
}
void inorder (tree t)
{   
    if(t !=NULL)
    {
        inorder (t->left);
        printf("%d", t->value);
        inorder (t->right);
    }
}
boolean member(element a, tree t)
{  
    if(t==NULL)
        return false;
    else
        if(a == t->value)
            return true;
        else
            if(member(a, t->left))
                return true;
            else
                return member(a, t->right);
}
int max(int a, int b)
{
    if ( a > b)
        return a;
    else
        return b;
}
int height_aux(tree t)
{
    if(empty (t))
        return 0; 
    else
        return ( 1+ max(height_aux(left(t)),height_aux(right(t))));
}
int height(tree t)
{   
    if(empty(t))
        return 0;
    else
        return (max(height_aux(left (t)), height ( right(t))));
}
element sum (tree t)
{  
}
int nnodes(tree t)
{   
    if(t == NULL)
        return 0;
    else
        return (1+nnodes(t->left) + nnodes(t->right));
}
int balance (tree t)
{ 
    
}
