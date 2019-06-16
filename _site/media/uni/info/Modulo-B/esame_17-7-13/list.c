#include "list.h"
void printlist(list l)
{
    if(l !=NULL)
    {
        printf("%s %s %d\n", l->P.cognome, l->P.nome, l->P.reddito);
        printlist(l->next);
    }
}
list cons_ins_list(char c[], char n[],int r, list l)
{
    list a;
    a=(list) malloc(sizeof(item));
    strcpy(a->P.nome, n);
    strcpy(a->P.cognome, c);
    a->P.reddito=r;
    a->next=l;
    return a;
}
list insord(persone P, list l)
{
    if(l == NULL)
        return ( cons_ins_list(P.cognome, P.nome, P.reddito, l));
    else
        if(strcmp(P.cognome, l->P.cognome)<0 ) //il cognome è < di quello già inserito
            return (cons_ins_list(P.cognome, P.nome, P.reddito, l));
        else
            if (strcmp(P.cognome, l->P.cognome)== 0) //i due cognomi sono uguali
            {
                if(strcmp(P.nome, l->P.nome)<0) //cognomi uguali, nome da inserire < di quello già inserito
                    return (cons_ins_list(P.cognome, P.nome, P.reddito, l));
                else 
                    if (strcmp(P.nome, l->P.nome)==0) //nomi e cognomi uguali
                    {
                        l->P.reddito+=P.reddito;
                        return l;
                    }
                    else //cognomi uguali, nome da inserire > di quello già inserito
                    {
                        l->next =insord(P, l->next);
                        return l;
                    }
            }
            else  //il cognome è > di quello inserito   
            {
                l->next=insord(P, l->next);
                return l;
            }
}