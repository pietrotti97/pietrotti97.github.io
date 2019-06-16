#include "tree.h"
int main() 
{
    FILE *p1, *p2;
    tree root =NULL;
    p1=fopen("parole1.txt","r");
    p2=fopen("parole2.txt","r");
    if ( p1 == NULL || p2==NULL)
    {
        printf("Sborate");
        exit(1);
    }
    else
    {
        root=reads_files(p1, p2, root);
    }
    printf("Stampa dell'albero ordinato:\n");
    printree(root);
    printf("\nFinitooo, n nodi = %d", nnodes(root));
    return (0);
}

