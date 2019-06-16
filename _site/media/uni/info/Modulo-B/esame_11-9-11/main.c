#include "tree.h"
int main()
{
    FILE *v, *i;
    tree root=NULL;
    v=fopen("vocaboli.txt","r");
    i=fopen("indice.bin","rb");
    if(v == NULL || i == NULL)
    {
        printf("Sborate");
        exit (1);
    }
    else
    {
       printf("Inizio\n");
       root=reads_files(v, i, root);
       printf("\nFinitoo\n");
    }
    printf("Stampa dell'albero: \n");
    showlist(root);
    printf("\nFinitoo\n");

    return (0);
}

