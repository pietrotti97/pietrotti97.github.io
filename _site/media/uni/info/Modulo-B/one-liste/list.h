/* 
 * File:   list.h
 * Author: pietro
 *
 * Created on 7 aprile 2018, 17.39
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct element
{
    int value;
    struct element *next;
}item;
typedef item *list;
typedef enum {TRUE,FALSE} boolean;
//parte delle funzioni di list.c
list testa(list L);
list coda(list L);
list ins_list(int el, list root);
list insord(int el, list root);
//list qsort_lis(list root);
list ins_end_list(int el, list root);
list insord_ric(int el, list root);
list sum_list(list L);
list elementz_list(list L);
boolean findel(list L);
void print_list(list L);

