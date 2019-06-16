#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "functions.h"
typedef int element;
typedef enum {false,true} boolean;

boolean isless(element a, element b);
boolean isequal(element a, element b);
element getelement(void);
void printelement(element a);
boolean isnull(element a);
element sumelement(element a, element a);


