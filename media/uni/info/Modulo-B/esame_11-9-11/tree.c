#include "tree.h"
tree cons_ins_tree(indice in, tree *l, tree *r)
{
    tree t;
    t=(node* ) malloc (sizeof(node));
    strcpy(t->in_t.parola, in.parola);
    t->in_t.pagina=in.pagina;
    t->left=l;
    t->right=r;
    return t;
}
tree insord(indice in, tree t)
{
    int n; 
    if(t == NULL)
        return cons_ins_tree(in, NULL, NULL);
    else
        if( (n=strcmp(in.parola, t->in_t.parola)) <0)
            return cons_ins_tree(t->in_t, insord(in, t->left), t->right);
        else
            if((n == 0))
            {
                printf("trovati due el uguali: %s %d, %s %d ->", in.parola,in.pagina, t->in_t.parola, t->in_t.pagina );
                t->in_t.pagina+=in.pagina;
                printf(".>updated pagina in tree: %d\n\n", t->in_t.pagina);
                return t;
            }
            else
                return cons_ins_tree(t->in_t, t->left, insord(in, t->right));
}
tree reads_files(FILE *v, FILE *i, tree t)
{
    indice in;
    char parola[20];
    while(fscanf(v, "%s",parola ) !=EOF)
    {
        //printf("Cerco -> %s\t", parola);
        while(fread(&in, sizeof(indice), 1, i) != 0)
        {
            //printf("%s %d\n", in.parola, in.pagina);
            if(strcmp(in.parola, parola)==0)
            {
                printf("Inserisco ->%s %d \n\n", in.parola, in.pagina);
                t=insord(in, t);
            }
                
        }
        rewind(i);
    }   
    return t;
}
void showlist(tree t)
{
    if(t !=NULL)
    {
        showlist (t->left);
        printf("> %s -> %d\n", t->in_t.parola, t->in_t.pagina);
        showlist (t->right);
    }
}