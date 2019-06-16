#include "main.h"
int cmpfunc(const void * a, const void * b)
{
	   return ( *(int*)a - *(int*)b );
}
int main()
{
	int k=0;
	int i,newval, c;
	do
	{

		if (k==0)
		{
			printf("Quanti elementi vuoi inserire? ");
			scanf("%d", &k);
		}
		else
		{
			printf("\nHai scazzato! Inserisci un numero consono di elementi: ");
			scanf("%d", &k);
		}
	}while (k>(dim+ n_val_v));
	for(i=0;i<k;i++)
	{
		printf("Inserisci il %d valore: ",i+1);
		scanf("%d", &newval);
		n_val_v=n_val_v +1;
		v[n_val_v-1]=newval;
		printf("\tInserito %d, ordinamento\n", v[n_val_v-1]);
		qsort(v,n_val_v, sizeof(int),cmpfunc);

	}
	printf("\n\nStampa del vettore ordinato:\t");
	for(c=0;c<n_val_v;c++)
	{
		printf("%d\t", v[c]);
	}
	printf("End_print\n\n");


	return 0;
}
