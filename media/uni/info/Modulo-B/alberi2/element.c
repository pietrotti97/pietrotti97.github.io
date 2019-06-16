#include "element.h"
boolean isless( element a, element b)
{
    if ( a < b)
        return TRUE;
    else
        return FALSE;
}
boolean isequal( element a, element b)
{
    if ( a == b)    
        return TRUE;
    else
        return FALSE;
}
void printelement( element a)
{
    printf("\t%d", a);
}
boolean isnull( element a)
{
    if (a == NULL)
        return TRUE;
    else
        return FALSE;
}
element sumelement( element a, element b)
{
    return a+b;
}