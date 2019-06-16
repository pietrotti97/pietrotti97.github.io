#include "el.h"
#include <stdio.h>
boolean isEqual(element e1, element e2)
{
    return (e1=e2);
}
boolean isLess(element e1, element e2)
{
    return (e1<e2);
}
element getElement()
{
    element e1;
    scanf ("%c", &e1);
    return e1;
}
void printElement (element e1)
{
    printf("%c", e1);
}
