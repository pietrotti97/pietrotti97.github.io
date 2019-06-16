#ifndef EL_H
#define EL_H
typedef char element;
typedef enum {false, true} boolean;
boolean isLess(element, element);
boolean isEqual(element, element);
element getElement(void);
void printElement(element);
#endif
