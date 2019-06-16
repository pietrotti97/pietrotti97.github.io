#include "list.h"
int main() 
{
    list L;
    int i=0, el, sum, elz, end;
    list root = NULL;
    int act=897;
    char torna;
do
{
    system("clear");
    printf("Welcome: \n");
    printf("[1]\tInserimento in testa\n");
    printf("[2]\tInserimento ordinato\n");
    printf("[3]\tInserimento in fondo alla lista: \n");
    printf("[4]\tStampa della lista\n");
    printf("[5]\tSomma degli el della lista\n");
    printf("[6]\tNumero degli el della lista: \n");          
    printf("[7]\tRicerca di un elemento in lista\n");
    printf("[8]\tInsord Ricorsiva\n");
    printf("[9\tQsort della lista\n");
    printf("\n\nCosa vuoi fare?\t");
    scanf ("%d", &act);
    switch (act)
    {
        case 1:
        {
            printf("Inserimento in testa\n");
            do
            {
                printf("\nInserire il %d elemento:\t ", i+1);
                scanf("%d", &el);
                if (el !=0)
                {
                    root=ins_list(el, root);
                    i++;
                }
                else 
                {
                    root=ins_list(0, root);
                }
            }while(el !=0);
            printf("\nInserimento Terminato!\n");
            printf("Inseriti %d elementi! \n", i);
            break;
        }
        case 2: 
        {
            printf("Inserimento Ordinato\n");
            do
            {
                printf("\nInserire il %d elemento:\t ", i+1);
                scanf("%d", &el);
                if (el !=0)
                {
                    root=insord(el, root);
                    i++;
                }
                else 
                {
                    root=insord(0, root);
                }
            }while(el !=0);
            printf("\nInserimento Terminato!\n");
            printf("Inseriti %d elementi! \n", i);
            break;
        }
        case 3:
        {
            printf("\n Inserimento in fondo alla lista: \t");
            scanf("%d", &end);
            root=ins_end_list(end, root);
            printf("\nInserimento terminato\n");
            break;
        }
        case 4:
        {
            printf("Stampa della lista\n");
            print_list(root);
            break;
        }
        case 5:
        {
            printf("\nSomma degli el della lista\t");
            printf("vale: %d\n", sum_list(root));
            break;
        }
        case 6:
        {
            printf("\nNumero degli el della lista: %d\n", elementz_list(root));
            break;
        }
        case 7:
        {
            if(findel(root))
            {
                printf("Found");
            }
            else
            {
                printf("Not found!");
            }
            break;
        }
        case 8:
        {
            printf("Inserimento Ordinato-Ricorsiva\n");
            do
            {
                printf("\nInserire il %d elemento:\t ", i+1);
                scanf("%d", &el);
                if (el !=0)
                {
                    root=insord_ric(el, root);
                    i++;
                }
                else 
                {
                    root=insord_ric(0, root);
                }
            }while(el !=0);
            printf("\nInserimento Terminato!\n");
            printf("Inseriti %d elementi! \n", i);
            break;
        }
        case 9:
        {
            printf("Sort della lista con algoritmo QSort:\n");
            //root=qsort_lis(root);
            break;
        }
        default:
        {
            printf("\nSborate mae\n");
        }
    }
    printf("\nTornare al menu' principale?");
    printf("\n[y] si");
    printf("\n[n] no\n");
    scanf("%s", &torna);
}while (torna !='n');
}


