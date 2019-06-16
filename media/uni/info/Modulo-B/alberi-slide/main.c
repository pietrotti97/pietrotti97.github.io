#include <stdio.h>
#include "tree.h"
void main(void)
{
    tree t1, t2;
    t1=cons_tree('b', NULL, NULL);
    t2=cons_tree('c', NULL, NULL);
    t1=cons_tree('*', t1, t2);
    t2=cons_tree('d', NULL, NULL);
    t1=cons_tree('-', t1, t2);
    t2=cons_tree('e', NULL, NULL);
    t1=cons_tree('/', t1, t2);
    t2=cons_tree('a', NULL, NULL);
    t1=cons_tree('+', t1, t2);
    printf("\nStampa in ordine: \n");
    inorder(t1);
}

