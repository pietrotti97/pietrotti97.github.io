#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
void print_intofile(FILE *C, tree t)
{
    if ( t!=NULL)
    {
        print_intofile(C, t->left);
        fprintf(C," %s, %d\n",t->P.name, t->P.scatole );
        print_intofile(C,t->right);
    }
}
int main() 
{
    FILE *A, *B, *C, *D;
    tree root = NULL;
    prodotti PRO;
    int x;
    A = fopen("elena.bin","rb");
    B=fopen("marta.txt","rt");
    D=fopen("elena_to.txt","w+");
    if(A== NULL || B==NULL)
    {
        printf("Sborate");
        exit(-1);
    }
    else
    {
        while (fscanf(B,"%s\t%d", PRO.name,&PRO.scatole ) !=EOF)
        {
            //printf("Prodotto %s ,%d\n", PRO.name,PRO.scatole);
            root=insord(PRO, root);
        }
        printf("Ended marta's file!\n");
        while (fread (&PRO, sizeof(PRO), 1, A) !=0)
        {
            //printf("Prodotto %s ,%d\n", PRO.name,PRO.scatole);
            fprintf(D," %s, %d\n",PRO.name, PRO.scatole );
            root=adds_an_el(PRO, root);
        }
        printf("Ended elena's file!\n");
    }
    /*printf("\nStampa albero\n\n");
    inorder(root);*/
    printf("creo il file:");
    C=fopen("output.txt", "w+");
    print_intofile(C, root);
    printf("\nFinitooo!");
    fclose(A);
    fclose(B);
    fclose (C);
    fclose (D);
    return (0);
}

