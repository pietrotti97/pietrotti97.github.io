#include <stdio.h>
#include <stdlib.h>
#include "list.h"
void findelz(list l, FILE *E, int i)
{
    if(l != NULL)
    {
        if( l->A.kcal >300)
        {
            fprintf(E,"Alimento %s, %d\n",l->A.product, l->A.kcal );
            i++;
        }
        return findelz(l->next,E, i);
    }
    fprintf(E, "\n\nTot= %d", i+1);
}
int main() 
{
    FILE *f, *E;
    list root=NULL;
    alimento a;
    int i=0;
    f =fopen("alimenti.bin", "rb");
    E= fopen("output.txt", "w+");
    if (f==NULL || E == NULL)
    {
        printf("Sborate");
        exit(-1);
    }
    else
    {
        while (fread(&a, sizeof(a), 1, f) !=0)
        {
            root=insord(a, root);
        }
    }
    //showlist(root);
    findelz(root, E, i);
    return (0);
}

