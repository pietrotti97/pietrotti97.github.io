#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int element;
typedef enum {FALSE, TRUE } boolean;

boolean isless (element a, element b);
boolean isequal( element a, element b);
element getelement (void );
void printelement(element a);
boolean isnull(element a);
element sumelement (element a, element b);

