//main.c
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "element.h"

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
