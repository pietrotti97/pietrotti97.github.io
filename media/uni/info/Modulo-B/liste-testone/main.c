#include <stdio.h>
#include <stdlib.h>
typedef struct element
{
    int value;
    struct element *next;
}item;
typedef item *list;
typedef enum {TRUE,FALSE} boolean;
/*
list ins_list(int el, list root)
{
    list L;
    L=(list)malloc(sizeof(item));
    L->value = el;
    L->next= root;
    return L;
}
*/
list ins_list(int el, list root)
{
    list L, pprec, patt=L, aux;
    int trovato=0;
    while((patt !=NULL) && (!trovato))
    {
        if(el < patt->value)
            trovato = 1;
        else
        {
            pprec=patt;
            patt=patt->next;
        }
    }
    aux =(list)malloc(sizeof(item));
    aux->value = el;
    aux->next=patt;
    if(patt == L)
        return aux;
    else
    {
        pprec ->next =aux;
        return L;
    }
}
list sum_list(list L)
{
    int som=0;
    while(L!=NULL)
    {
        som=som+(L->value);
        L=L->next;
    }
    return som;
}
list elementz_list(list L)
{
    int ele=0;
    while(L!=NULL)
    {
        ele++;;
        L=L->next;
    }
    return ele;
}
boolean findel(list L)
{
    int cerc, elm;
    printf("Elemento da cercare: \t");
    scanf("%d", &cerc);
    while (L !=NULL)
    {
        elm=L->value;
        if(cerc ==elm )
        {
            return 1;
        }
        else
        {
            L=L->next;
        }
            
    }
    return 0;
}

void print_list(list L)
{
    int i=0;
    printf("Stampa della lista!\n");
    
    while (L !=NULL)
    {
        printf("\nValore %d e': %d",i+1,L->value);
        i++;
        L=L->next;
    }
}
int main() 
{
    list L;
    int i=0, el, sum, elz;
    list root = NULL;
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
    print_list(root);
    printf("\n");
    printf("\nSomma degli el della lista\n");
    sum=sum_list(root);
    printf("\nSomma degli el della lista: %d\n", sum);
    elz=elementz_list(root);
    printf("\nIl numero degli el della lista: %d\n", elz);
    if(findel(root))
    {
        printf("Found");
    }
    else
    {
        printf("Not found!");
    }
    printf("\n\n!End!\n");
    return (0);
}

