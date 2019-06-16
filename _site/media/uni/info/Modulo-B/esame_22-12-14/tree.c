#include "tree.h"
tree cons_ins_tree( char C[], tree l, tree r)
{
    tree t;
    t=(nodo *)malloc (sizeof (nodo));
    strcpy(t->parola, C);
    t->left=l;
    t->right=r;
    return t;
}
tree insord( char C[], tree t)
{
    if(t== NULL)
        return cons_ins_tree(C, NULL, NULL);
    else
        if(strcmp(C, t->parola)<0)
            return cons_ins_tree(t->parola, insord(C, t->left), t->right);
        else
            return cons_ins_tree(t->parola, t->left, insord(C, t->right));
}
void showlist(tree t)
{
    if(t !=NULL)
    {
        showlist (t->left);
        printf("%s\n",t->parola );
        showlist(t->right);
    }
}