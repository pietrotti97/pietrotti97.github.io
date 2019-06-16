#include <string.h>
#include "tree.h"
tree ins_cons_tree(prodotti PRO, tree l, tree r)
{
    tree P;
    P=(nodo *) malloc(sizeof(nodo));
    strcpy(P->P.prodotto, PRO.prodotto);
    P->P.scatole=PRO.scatole;
    P->left=l;
    P->right=r;
    return P; 
}
tree insord (prodotti PRO, tree t)
{
    if(t ==NULL)
        return ins_cons_tree(PRO, NULL, NULL);
    else
        if(strcmp(PRO.prodotto, t->P.prodotto)<0)
            return ins_cons_tree(t->P,insord(PRO,t->left ), t->right );
        else
            return ins_cons_tree(t->P, t->left, insord(PRO, t->right)); 
}
void printree(tree t)
{
    if(t !=NULL)
    {
        printree(t->left);
        printf("Alimento: %s, %d\n", t->P.prodotto, t->P.scatole);
        printree(t->right);
    }
}
int chk_el(int s, int st)
{
    if(st >=s)
        return (1);
}
int findel(prodotti PRO, tree t)
{
    int str;
    if (t!=NULL)
    {
        str=strcmp(PRO.prodotto, t->P.prodotto);
        if(str == 0)
            return (chk_el(PRO.scatole, t->P.scatole));
        else
            if(str <0)
                return findel(PRO, t->left);
            else
                return findel(PRO, t->right);
    }
}