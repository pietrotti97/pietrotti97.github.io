#include "tree.h"
tree cons_ins_tree(char w1[], tree l, tree r)
{
    tree p;
    p=(nodo *) malloc(sizeof(nodo));
    strcpy(p->P, w1);
    p->left=l;
    p->right=r;
    return (p);
}
tree insord(char w1[],tree t)
{
    if (t ==NULL)
        return cons_ins_tree(w1, NULL, NULL);
    else
        if(strcmp (w1, t->P)<=0)
            return cons_ins_tree(t->P, insord(w1, t->left), t->right);
        else
            return cons_ins_tree(t->P, t->left, insord(w1, t->right));
}
int ispresent(char w1[], tree t)
{
    int str;
    
    if(t !=NULL)
    {
        str=strcmp(w1, t->P);
        if(str==0)
            return 1;
        else
            if(str < 0)
                return ispresent(w1, t->left);
            else
                return ispresent (w1,t->right); 
    }
    else
        return 2;
}
tree reads_files(FILE *p1,FILE *p2,tree t)
{
    char w1[20], w2[20];
    int i=0;
    while (fscanf(p1,"%s",w1)!=EOF)
        {
            //printf("\n\nVal:%s\n", w1);
            while (fscanf(p2,"%s", w2)!= EOF)
            { 
                if(strcmp(w1, w2) == 0)
                { 
                    i++;
                }
                //printf("i=%d, %s\t",i ,w2);
            }   
            if((i == 0) && ispresent ( w1, t) == 2)
            {
                t=insord(w1, t);
            }
            rewind(p2);
            i=0;
        }
    return t;
}
void printree(tree t)
{
    if(t !=NULL)
    {
        printree(t->left);
        printf("%s \t", t->P);
        printree(t->right);   
    }
}
int nnodes(tree t)
{
    if(t ==NULL)   
        return 0;
    else
        return (1+nnodes(t->left)+ nnodes(t->right));
}