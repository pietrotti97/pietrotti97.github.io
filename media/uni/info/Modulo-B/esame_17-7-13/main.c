#include "list.h"
int main() 
{
    FILE *u;
    list root = NULL;
    persone P;
    if((u=fopen("uno.txt", "r"))==NULL)
    {
        printf("Sborate");
        exit(1);
    }
    else
    {
        while(fscanf(u,"%s %s %d",P.cognome, P.nome, &P.reddito ) !=EOF)
        {
            //printf("Pipol: %s %s %d \n", P.cognome, P.nome, P.reddito);
            root=insord(P, root);
        }
        fclose(u);
    }
    printf("Stampa della Lista: \n");
    printlist(root);
    printf("\nFinitooo \n");
    return (0);
}

