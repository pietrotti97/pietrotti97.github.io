#include "list.h"
#include <stdio.h>
#include <stdlib.h>
list cons_ins(alimento a, list l)
{
    list T;
    T=(list) malloc(sizeof(item));
    strcpy(T->A.product,a.product);
    T->A.kcal=a.kcal;
    T->next=l;
    return T;    
}
list insord ( alimento a, list l)
{
    if (l ==NULL)
        return (cons_ins(a, l));
    else
        if(strcmp(a.product, l->A.product)<0)
            return (cons_ins(a, l));
        else
        {
            l->next=insord(a, l->next);
            return l;
        } 
}
void showlist(list l)
{
    if(l !=NULL)
    {
        printf("\nAlimento: %s, %d", l->A.product, l->A.kcal);
        return (showlist (l->next));
    }
   
}
