#include "element.h"
#include <stdio.h>
#include <stdlib.h>
boolean isless(element a, element b)
{
    if (a > b)
        return 0;
    else
        return 1;
}
boolean isequal(element a, element b)
{
    if (a == b)
        return 1;
    else
        return 0;
}
element getelement(void)
{
    int el;
    printf("\nInserisci elemento: \t");
    return scanf("%d",&el );
}
void printelement(element a)
{
    printf("%d\t", a);
}
boolean isnull(element a)
{
    if(a != 0)
        return 1;
    else
        return 0;
}
element sumelement(element a, element b)
{
    return a+b;
}
