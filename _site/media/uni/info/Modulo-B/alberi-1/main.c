
#include <stdio.h>
#include <stdlib.h>
#include "element.h"
/*
 * 
 */
int main() 
{
    char act;
    char torna;
do
{
    system("clear");
    printf("Welcome: \n");
    printf("[>]\tEsegue stampa preorder:\n");
    printf("[<]\tEsegue stampa postorder:\n");
    printf("[i]\tEsegue stampa inorder: \n");
    printf("[/]\tRicerca di un eleemento:\n");
    printf("[h]\tCalcola l'altezza dell'albero:\n");
    printf("[s]\tCaalcola la somma degli el dell'albero:\n");          
    printf("[n]\tCalcola il numero di nodi:\n");
    printf("[b]\tCalcola il bilanciamento dell'albero\n");
    printf("[e]\tEsci dal programma\n");
    printf("\n\nCosa vuoi fare?\t");
    scanf ("%c", &act);
    switch (act)
    {
        case ">":
        {
            break;
        }
        case "<": 
        {
            break;
        }
        case "i":
        {
            break;
        }
        case "/":
        {
            break;
        }
        case "h":
        {
            break;
        }
        case "s":
        {
            break;
        }
        case "n":
        {
            break;
        }
        case "b":
        {
            break;
        }
        case "e":
        {
            break;
        }
        default:
        {
            printf("\nSborate mae\n");
            exit 0;
        }
    }
    printf("\nTornare al menu' principale?");
    printf("\n[y] si");
    printf("\n[n] no\n");
    scanf("%s", &torna);
}while (torna !='n');
}

