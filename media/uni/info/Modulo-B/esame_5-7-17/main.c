#include <stdio.h>
#include <stdlib.h>
#include "list.h"
int main() 
{
    FILE *F;
    list root = NULL;
    int x, y;
    F=fopen("punti1.txt", "rt");
    if ( F == NULL)
    {
        printf(" File non trovato\n");
        exit(-1);
    }
    else
    {
        while(fscanf(F,"%d %d", &x, &y ) != EOF)
        {
            if(x<y)
                root=insord(x,y, root);
        }
    }
    showlist(root);
    return (0);
}