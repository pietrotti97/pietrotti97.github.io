//element.c
#include <stdio.h>
#include <string.h>
#include "element.h"

boolean isLess(element e1, element e2) {
	if (strcmp(e1.cognome, e2.cognome) < 0)
		return true;
	else
	if (strcmp(e1.cognome, e2.cognome) == 0)
	if (strcmp(e1.nome, e2.nome) < 0)
		return true;
	else
		return false;
	else
		return false;
}

boolean isEqual(element e1, element e2) {
	if ((strcmp(e1.cognome, e2.cognome) == 0) && (strcmp(e1.nome, e2.nome) == 0))
		return true;
	else
		return false;
}

element getElement() {
	element el;
	printf("\nInserisci cognome: ");
	scanf("%s", el.cognome);
	printf("\nInserisci nome: ");
	scanf("%s", el.nome);
	printf("\nInserisci media: ");
	scanf("%f", &el.media);

	return el;
}

void printElement(element el) {
	printf("Studente: %s %s\n\tmedia: %f\n", el.cognome, el.nome, el.media);
}
