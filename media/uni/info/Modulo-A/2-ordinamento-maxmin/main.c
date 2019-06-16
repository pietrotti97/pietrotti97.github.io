/*
 * main.c
 *
 *  Created on: 16 lug 2017
 *      Author: pietro
 */
#include <stdio.h>
#include <stdlib.h>
#define N 15
typedef int vettore[N];
int minimo(vettore vet)
{
	int i, min;
	for (min=vet[0], i=1 ; i<N ; i++)
	{
		if(vet[i]<min)
			min = vet[i];
	}
	/*min = 3;*/
	return min;
}
int massimo(vettore vet)
{
	int i, max;
	for(max = vet[0], i=1; i<N; i++)
	{
		if(vet[i]>max)
			max = vet[i];
	}
		/*max = 5;*/
		return max;
}

void main(void)
{
	int i;
	vettore a;
	printf("Inserire %d numeri interi: \n", N);
	for(i=0;i<N;i++)
	{
		scanf("%d", &a[i]);
	}
	printf(" Il minimo vale %d, Il massimo vale %d", minimo(a), massimo(a));
	return 0;
}

