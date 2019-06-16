#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list testa(list L)
{
    if(L==NULL)
        abort();
    else
        return L->value;
}
list coda(list L)
{
    while(L==NULL)
    {
      return L->next; 
    }
        
}
list ins_list(int el, list root)
{
    list L;
    L=(list)malloc(sizeof(item));
    L->value = el;
    L->next= root;
    return L;
}
list insord(int el, list root) 
{
    list pprec, patt=root, aux;
    int trovato=0;
    while((patt !=NULL) && (!trovato))
    {
        if(el < patt->value)
            trovato = root;
        else
        {
            pprec=patt;
            patt=patt->next;
        }
    }
    aux =(list)malloc(sizeof(item));
    aux->value = el;
    aux->next=patt;
    if(patt == root)
        return aux;
    else
    {
        pprec ->next =aux;
        return root;
    }
}
/*list qsort_lis(list root)
{
    list aux, end, L=root;
    int val;
    while (L !=NULL)
    {
        val= L->value;
        L= L->next;
        if(L->value >= val) 
        {
            end->value= val;
            end->next=L;
        }
        else
        { 
            end->value = L->value;
            end->next=;
        }
    }
    
    return 1; 
}*/
list ins_end_list(int el, list root)
{
    list prec, aux;
    list patt=root;
    aux=(list) malloc (sizeof(item));
    aux ->value = el;
    aux->next = NULL;
    if (root == NULL)
        return aux;
    else
    {
        while (patt !=NULL)
        {
            prec = patt;
            patt = patt->next;
        }
        prec-> next = aux;
        return root;
    }
}
list insord_ric(int el, list root)
{
    if ( root ==NULL)
        return ins_list(el, root);
    else 
        if(el <= root->value)
            return ins_list(el, root);
        else
        {
            root->next = insord(el, root->next);
            return root;
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