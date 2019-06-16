//element.h
#ifndef ELEMENT_H
#define ELEMENT_H

#define DIM_STR 20 

typedef struct {
	char nome[DIM_STR];
	char cognome[DIM_STR];
	float media;
} element;

typedef enum { false, true } boolean;

boolean isLess(element, element); //DICHIARAZIONI
boolean isEqual(element, element);
element getElement(void);
void printElement(element);

#endif
