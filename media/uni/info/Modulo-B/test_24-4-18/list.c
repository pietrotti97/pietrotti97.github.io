#include "list.h"

list cons(list l, element el)
{
    list t;
    t = (list) malloc(sizeof(NODO));
    t->value = el;
    t->next = l;
    return t;
}
list insord(list l, element el)
{
    if (l == NULL) 
       return cons(l, el);
    else 
        if (strcmp(el.nome, l->value.nome)<0) 
            return cons(l, el);
        else
        {
            l->next = insord(l->next, el);
            return l;
        }
}
void showlist(list l)
{
    if (l != NULL)
    {
	printf("%s -> %d \n", l->value.nome, l->value.kcal);
	showlist(l->next);
    }
}