#include "tree.h"
int is_a_vocal(char e)
{
    int i;
    char vocals[]="aeiou";
    //printf("%c", e);
    for(i=0;i<5;i++)
        if(e == vocals[i])
            return 1;
    return 0;
}
int main() 
{
    FILE *p;
    char w[20];
    
    tree root = NULL;
    if((p=fopen("parole1.txt","r"))==NULL)
    {
        printf("Sborate");
        exit(1);
    }
    else
    {
        while(fscanf(p,"%s",w ) !=EOF)
        {
            
            if(is_a_vocal(w[0]) == 1)
            {
                /*printf("%s\t", w);
                printf("is a  vocal\n");*/
                root=insord(w, root);
            }
                
        }
        fclose(p);
    }
    showlist(root);
    return (0);
}

