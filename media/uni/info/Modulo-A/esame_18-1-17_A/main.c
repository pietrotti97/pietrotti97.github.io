#include <stdio.h>
#include <stdlib.h>
#define cartella "cartelle.txt"
typedef struct
{
	char Gamer[20];
	int n[15];
}cartella_s;
int read_ext(int ext[])
{
	FILE *f;
	int i=0;
	f=fopen("estratti.txt","r");
	if(f==NULL)
	{
		printf("Sborat");
		return 1;
	}
	else
	{
		while(!feof(f))
		{
			fscanf(f,"%d", &ext[i]);
			i++;
		}
	return i;
	}
}
int read_cart(cartella_s cart[])
{
	FILE *f;
	int l=0, i=0;
	f=fopen(cartella,"r");
	if(f==NULL)
	{
		printf("Sborat!");
		return 1;
	}
	else
	{
		while(!feof(f))
		{
			fscanf(f,"%s",cart[i].Gamer);
			for(l=0;l<15;l++)
			{
				fscanf(f,"%d",&cart[i].n[l]);
			}
			i++;
		}
		return i;
	}

}
void print_ext(int ext[], int n_ext)
{
	int i;
	printf("Stampo Estratti:\n");
	for(i=0;i<n_ext;i++)
	{
		printf("%d ", ext[i]);
	}
	printf("\nEnd\n");
}
void print_cart(cartella_s cart[], int n_cart)
{
	int i,n;
	printf("\nStampo giocatori e cartella :\n");
	for(i=0;i<n_cart;i++)
	{
		printf("\n%s\t", cart[i].Gamer);
		for(n=0;n<15;n++)
		{
			printf("%d ",cart[i].n[n]);
		}
	}
	printf("\nEnd\n");
}
int count_steps(int ext[], int n_ext, cartella_s cart[],int el_cart)
{
	int a=0,b=0;
	int found=0, not_found=0, tot;
	while(a<n_ext)
	{

		while(b<15)
		{
			if(cart[el_cart].n[b] == ext[a])
			{
				found++;
				b=16;
			}
			else
			{
				b++;
			}
		}
		if(b==15)
		{
			not_found++;
		}
		b=0;
		if(found == 15)
		{
			a=n_ext+10;
		}
		a++;
	}
	tot=found+not_found;
	return tot;
}
int findless(int step[], int n_cart)
{
	int i, n;
	n=step[0];
	for(i=0;i<n_cart; i++)
	{
		if(n>step[i])
		{
			n=step[i];
		}
	}
	return n;
}
int find_winner(int step[], int n_cart, cartella_s cart[])
{
	int win_step, i=0;
	int winner=0;
	printf("Finding a Winner:\n");
	win_step=findless(step,n_cart);
	while(i<n_cart)
	{
		if(win_step == step[i])
		{
			winner = i;
			i=n_cart+10;
		}
		else
		{
			i++;
		}
	}
	return winner;
}
void func(int ext[], int n_ext, cartella_s cart[], int n_cart)
{
	int a=0;
	int step[n_cart];
	int winner;
	for(a=0;a<n_cart;a++)
	{
		printf("Gamer=%20s",cart[a].Gamer);
		step[a]=count_steps(ext,n_ext,cart,a);
		printf("\tstep= %d \n", step[a]);
	}
	winner=find_winner(step, n_cart, cart);
	printf("And the winner is: %s", cart[winner].Gamer);
}
int main()
{
	cartella_s cart[10];
	int n_ext, n_cart;
	int ext[90];
	n_ext=read_ext(ext);
	//print_ext(ext, n_ext);
	n_cart=read_cart(cart);
	//print_cart(cart, n_cart);
	func(ext, n_ext, cart, n_cart);
	return 0;
}
