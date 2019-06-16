#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_STR 20
typedef struct {
	char nome[DIM_STR];
	char cognome[DIM_STR];
	float media;
} element;

typedef struct node	{
	element value;
	struct node* next;
} listNode;
typedef listNode *list;



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







typedef enum { false, true } boolean;

int menu(void);

void main() {//variabili locali al main
	list l1 = emptyList(), l2 = emptyList(), l3 = emptyList();
	element el;
	int l1_size = 0, l2_size = 0;
	int i = 0;
	FILE *f1, *f2;
	int n = 0, m = 0;

	// Creazione prima lista
	printf("Numero elementi per la lista 1:\n");
	scanf("%d", &n);
	printf("Lettura file per l1\n");
	//f1 = fopen("..\\..\\..\\..\\..\\Google Drive\\Tutorato INFO B\\Anno 2014_2015\\Es.5\\Es.5\\Esercizio 2\\studenti1.txt", "rt");
	f1 = fopen("studenti1.txt", "rt");
	if (f1 == NULL) {
		printf("Errore di apertura");
		return;
	}

	while (!feof(f1) && i < n) {
		fscanf(f1, "%s", el.nome);
		fscanf(f1, "%s", el.cognome);
		fscanf(f1, "%f", &el.media);
		l1 = insOrd(el, l1);
		i++;
	}
	fclose(f1);

	i = 0;

	printf("Numero elementi per la lista 2:\n");
	scanf("%d", &m);
	// Creazione seconda lista
	printf("Lettura file per l2\n");
	//f2 = fopen("..\..\..\..\..\Google Drive\Tutorato INFO B\Anno 2014_2015\Es.5\Es.5\Esercizio 2\studenti2.txt", "rt");
	f2 = fopen("studenti2.txt", "rt");
	if (f2 == NULL) {
		printf("Errore di apertura");
		return;
	}

	while (!feof(f2) && i < m) {
		fscanf(f2, "%s", el.nome);
		fscanf(f2, "%s", el.cognome);
		fscanf(f2, "%f", &el.media);
		l2 = insOrd(el, l2);
		i++;
	}
	fclose(f2);

	while (true) {
		int choice = menu();
		switch (choice) {
		case 1:
			printf("Corso 1:\n");
			showlist(l1);
			printf("Corso 2:\n");
			showlist(l2);
			break;
		case 2:
			printf("Creo elemento da cercare.\n");
			el = getElement();
			if (member(el, l1))
				printf("Trovato in l1!\n");
			else
			if (member(el, l2))
				printf("Trovato in l2!\n");
			else
				printf("Non trovato!\n");
			break;
		case 3:
			printf("Creo elemento da eliminare in l1.\n");
			el = getElement();
			l1 = deleteValue(el, l1);
			showlist(l1);
			break;
		case 4:
			l3 = append(l1, l2);
			showlist(l3);
			break;
		case 5:
			printf("Copio l1 in nuova lista...\n");
			l3 = copy(l1);
			printf("Stampo l1...\n");
			showlist(l1);
			printf("Stampo nuova lista...\n");
			showlist(l3);
			break;
		case 6:
			l3 = merge(l1, l2);
			showlist(l3);
			break;
		case 7:
			printf("Lunghezza l1: %d\nLunghezza l2: %d\n", length(l1), length(l2));
			break;
		case 8:
			l3 = reverse(l1);
			showlist(l3);
			break;
		case 9:
			printf("Inserire posizione inizio sublist\n");
			scanf("%d", &choice);
			if (choice >= length(l1))
				printf("Valore inserito errato!\n");
			else {
				l3 = sublist(choice, l1);
				showlist(l3);
			}
			break;
		case 10:
			exit(0);
		default:
			printf("Comando non riconosciuto");
		}
	}


}//fine main

int menu() {
	int choice = 0;
	printf("Digitare:\n");
	printf("\t1)  Visualizzare tutti gli studenti\n");
	printf("\t2)  Cercare uno studente\n");
	printf("\t3)  Cancellazione di uno studente\n");
	printf("\t4)  Append delle due liste\n");
	printf("\t5)  Copia della lista l1 in una terza lista\n");
	printf("\t6)  Merge delle due liste\n");
	printf("\t7)  Stampare il numero di studenti nelle due liste\n");
	printf("    Funzioni non richieste dall'esercizio\n");
	printf("\t8) Reverse di l1\n");
	printf("\t9) Sublist di l1\n");
	printf("\t10) Esci\n");
	scanf("%d", &choice);
	return choice;

}
