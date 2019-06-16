//list.c
#include <stdio.h>
#include <stdlib.h>
#include "list.h"


/*FUNZIONI PRIMITIVE DEL TIPO DI DATO ASTRATTO LISTA SEMPLICE*/

element head(list l){	/*funzione che emette il valore del campo del primo elemento della lista l*/
	if (empty(l))
		abort();
	else
		return l->value;
}


list tail(list l){	/*fornisce il puntatore all'elemento successivo a quello che il puntatore l punta*/
	if (empty(l))
		abort();
	else
		return l->next;
}


list emptyList(){	/*funzione che fornisce una lista vuota*/
	return NULL;
}


boolean empty(list l){	/*test che stabilisce la lista passata come parametro è vuota o meno*/
	if (l == NULL)
		return true;
	else
		return false;
}


list cons(element el, list l){
	list aux = emptyList();

	aux = (list)malloc(sizeof(listNode));
	aux->value = el;
	aux->next = l;
	return aux;
}

/* inserimento in coda in una lista */
list consTail(element el, list l)
{
	if (empty(l)){
		return cons(el, l);
	}
	else
	{
		l->next = consTail(el, tail(l));
		return l;
	}
}

void showlist(list l){
	if (empty(l))
		printf("\n");
	else {
		printElement(head(l));
		showlist(tail(l));
	}
}

/* copia di una lista */
list copy(list l) {
	if (empty(l)) return NULL;
	else return cons(head(l), copy(tail(l)));
}

/* ricerca di un elemento in una lista */
boolean member(element el, list l){
	if (empty(l))
		return false;
	else if (isEqual(el, head(l)))
		return true;
	else
		return member(el, tail(l));
}

int length(list l)
{
	if (empty(l))
		return 0;
	else
		return 1 + length(tail(l));
}

/*APPEND DI DUE LISTE: "si inseriscono in fondo alla lista L1 tutti gli elementi della lista L2"*/
list append(list l1, list l2)
{
	if (empty(l1))
		return copy(l2);
	else
	{
		return cons(head(l1), append(tail(l1), l2));
	}
}

/*cancellazione di un elemento dalla lista non ordinata*/
list deleteValue(element n, list l)
{
	list temp = NULL;
	if (empty(l))
		return emptyList();
	else if (isEqual(n, head(l)))
	{
		temp = tail(l);
		free(l);
		return temp;
	}
	else
	{
		l->next = deleteValue(n, tail(l));
		return l;
	}
}


list insOrd(element el, list l)
{

	/* caso di lista vuota */
	if (empty(l)) {
		return cons(el, l);
	}

	/* l'elemento va messo in prima posizione */
	if (isLess(el, head(l))) {
		return cons(el, l);
	}

	/* l'elemento va aggiunto al resto della lista */
	return cons(head(l), insOrd(el, tail(l)));
}


list merge(list l1, list l2) {
	if (!empty(l1) && !empty(l2))
	{
		if (isLess(head(l1), head(l2)))
			return cons(head(l1), merge(tail(l1), l2));
		else
			return cons(head(l2), merge(l1, tail(l2)));
	}

	if (empty(l1) && !empty(l2))
		return cons(head(l2), merge(l1, tail(l2)));
	else if (!empty(l1) && empty(l2))
		return cons(head(l1), merge(tail(l1), l2));
	else
		return emptyList();
}

/*

 FUNZIONI NON RICHIESTE DALL'ESERCIZIO
 lE ABBIAMO MESSE IN MODO DA DARVI ALTRI ESEMPI DI POSSIBILI FUNZIONI SU LISTE

 */

/*ribaltamento della lista l*/
list reverse(list l)
{
	if (empty(l))
		return emptyList();
	else
		return append(reverse(tail(l)), cons(head(l), emptyList()));
}

/* creazione di una sottolista */
list sublist(int k, list l)
{
	if (empty(l)) {
		return emptyList();
	}

	if (k == 0) {
		return l;
	}

	return sublist(--k, tail(l)); //pre-decremento (diverso da k--, post-decremento)
}
