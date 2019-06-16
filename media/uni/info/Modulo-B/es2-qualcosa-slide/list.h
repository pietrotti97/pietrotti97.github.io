//list.h
#include "element.h"
#include <stdlib.h>

typedef struct node	{
	element value;
	struct node* next;
} listNode;
typedef listNode *list;

/*prototipi delle funzioni implementate nella struttura dati
astratta lista*/
list emptyList();					/*funzione che fonisce una lista vuota*/
element head(list l);				/*funzione che emette il valore del campo del primo elemento della lista l*/
list tail(list l);					/*fornisce il puntatore all'elemento successivo a quello che il puntatore l punta*/
boolean empty(list l);				/*test che stabilisce la lista passata come parametro è vuota o meno*/
list cons(element n, list l);		/*inserimento di un nuovo elemento in testa alla lista*/

/* funzioni basate sulle funzioni di base (precedentemente dichiarate */
list consTail(element n, list l);	/*inserimento di un nuovo elemento in fondo alla lista*/
void showlist(list l);				/*stampa di tutti gli elementi della lista*/
list copy(list l);					/*copia la lista l in un'altra lista senza condivisione di struttura*/
boolean member(element el, list l);	/*ricerca di un valore*/
int length(list l);					/*lunghezza di una lista*/
list append(list l1, list l2);		/*crea una lista composta dalla lista l1 seguita dalla lista l2*/
list deleteValue(element el, list l);		/*Elimina el dalla lista l*/

list insOrd(element el, list l);	/* funzione che effettua l'inserimento ordinato dell'elemento n nella lista L*/
list merge(list l1, list l2);		/*unisce due liste ordinate in una terza lista ordinata anch'essa*/
/*
 FUNZIONI NON RICHIESTE DALL'ESERCIZIO
 lE ABBIAMO MESSE IN MODO DA DARVI ALTRI ESEMPI DI POSSIBILI FUNZIONI SU LISTE
 */
list reverse(list l);				/*Crea una nuova lista rovesciata*/
list sublist(int k, list l);		/*creazione di una sottolista*/

