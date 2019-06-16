#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
	char nome[20];
	int peso;
}ingredienti_s;
int read(ingredienti_s  n[],FILE *f )
{
	int i=0;
	while(!feof(f))
	{
		fscanf(f,"%s %d", n[i].nome, &n[i].peso);
		i++;
	}
	return i;
}
int de(ingredienti_s i[], ingredienti_s r[], int *ing_n, int *ric_n)
{
	FILE *ing;
	FILE *ric;
	ing=fopen("ingredienti.txt","r");
	ric=fopen("ricetta2.txt","r");
	if((ing==NULL)||(ric==NULL))
	{
		printf("Sborat\nTerminated");
		return -1;
	}
	*ing_n=read(i, ing);
	*ric_n=read(r, ric);
	return 1;
}
void print_ting(ingredienti_s i[], ingredienti_s r[], int ing_n, int ric_n)
{
	int o=0;
	printf("\n\nLista Ingredienti:");
	for(o=0;o<ing_n;o++)
	{
		printf("\n%s %d", i[o].nome, i[o].peso);
	}
	printf("\n\nRicetta:");
	for(o=0;o<ric_n;o++)
	{
		printf("\n%s %d", r[o].nome, r[o].peso);
	}
}
int less_ric(int n[],int i, int max, int p)
{
	if(i>max)
	{
		return(p);
	}
	else
	{
		if(n[p]<n[p+1])
			{
				i++;
				return(less_ric(n,i,max,p));
			}
			else
			{
				i++;
				return(less_ric(n,i,max,p+1));
			}
	}

}
int find_less(int n[], int o)
{
	int l;
	l=less_ric(n,0,o,0);
	return l;
}
int goes()
{
	int n, res;

}
int skraap(ingredienti_s i[], ingredienti_s r[], int ing_n, int ric_n)
{
	int a, b=0,var=0;
	int n[ric_n], res[ric_n];
	int less;
	for(a=0;a<ric_n;a++)
	{
		while(strcmp(r[a].nome,i[b].nome))
		{
			b++;
		}
		n[var]=i[b].peso/r[a].peso;
		res[var]=i[b].peso%r[a].peso;
		printf("n=%d\n", n[var]);
		printf("res= %d \n", res[var]);
		var++;
		b=0;
	}
	less=find_less(n,ric_n);
	printf("\n less=%d", n[less]);
}
int main()
{
	int ing_n, ric_n;
	ingredienti_s i[100], r[100];
	de(i,r,&ing_n,&ric_n);
	//print_ting(i, r, ing_n, ric_n);
	skraap(i, r, ing_n, ric_n);

	return 0;
}
