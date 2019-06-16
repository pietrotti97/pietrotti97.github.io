#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
tree cons_ins_tree(prodotti PRO, tree l, tree r )
{
    tree t;
    t=(nodo *) malloc(sizeof(nodo));
    strcpy(t->P.name, PRO.name);
    t->P.scatole=PRO.scatole;
    t->left=l;
    t->right=r;
    return t;
}
tree insord(prodotti PRO, tree T)
{
    if(T==NULL)
        return cons_ins_tree(PRO, NULL, NULL);
    else
        if(strcmp(PRO.name, T->P.name)<0)
            return cons_ins_tree(T->P,insord(PRO, T->left), T->right);
        else
            return cons_ins_tree(T->P,T->left, insord(PRO, T->right) );
}
void inorder( tree t)
{
    if ( t!=NULL)
    {
        inorder (t->left);
        printf(" %s, %d\n", t->P.name, t->P.scatole);
        inorder(t->right);
    }
}
int finds_elz(prodotti PRO, tree t)
{
    if(t==NULL)
        return 1;
    else
        if( strcmp (PRO.name, t->P.name)== 0)
        {
            t->P.scatole=t->P.scatole+PRO.scatole;
        }
        else
            if (strcmp(PRO.name, t->P.name)<0)
                return finds_elz(PRO, t->left);
            else
                return finds_elz(PRO, t->right);

}
tree adds_an_el(prodotti PRO, tree t)
{
    if(t ==NULL)
        return (cons_ins_tree(PRO, NULL, NULL));
    else
    {
        if(finds_elz(PRO, t) ==1)
        {
            return (insord(PRO, t));              
        }
        else
            return t;
             
    }
}