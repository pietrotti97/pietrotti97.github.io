#include <stdio.h>
#include <stdlib.h>
#include "list.h"
list ins_cons(int x, int y, list l)
{
    list t;
    t = (list) malloc (sizeof(item));
    t->a.x = x;
    t->a.y= y;
    t->next=l;
    return t;
}
list insord( int x, int y, list l)
{
    if ( l== NULL)
        return (ins_cons (x, y, l));
    else
        if(x < l->a.x)
            return (ins_cons(x, y, l));
        else
        {
            l->next=insord(x, y, l->next);
            return l;
        }
}
void showlist(list l)
{
    if ( l!= NULL)
    {
        printf("\nX = %d, Y = %d ", l->a.x , l->a.y);
        showlist(l->next);
    }
}