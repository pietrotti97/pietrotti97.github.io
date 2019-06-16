#include "tree.h"
void print_intofile(prodotti PRO, FILE *O)
{
    fprintf(O, "Disponibile: %s\n\n", PRO.prodotto);
}
void search_intofile(prodotti PRO, FILE *P, tree t)
{
    FILE *O;
    if ((O=fopen("output.txt","w+"))==NULL)
    {
        printf("Sborate2");
        exit (1);
    }
    else
    {
        while (fscanf(P, "%s %d", PRO.prodotto, &PRO.scatole) !=EOF)
        {
            //printf("\nSearching for. %s, %d", PRO.prodotto, PRO.scatole);
            if(findel(PRO, t)==1)
                print_intofile(PRO, O);
        }
        
    }
    fclose (O);
}
int main() 
{
    FILE *A, *P;
    prodotti PRO;
    tree root = NULL;
    A=fopen("alimenti.bin","rb");
    P=fopen("pranzo.txt","r");
    if (A==NULL || P==NULL)
    {
        printf("sborate\n");
        exit(1);
    }
    else
    {
        while (fread(&PRO, sizeof(PRO), 1, A)!=0)
        {
            //printf("%s, %d\n", PRO.prodotto, PRO.scatole);
            root=insord(PRO, root);
        }
        printf("Inizio carestia\n");
        search_intofile(PRO, P, root);
    }
    //printree(root);
    printf("ended");
    return (0);
}

