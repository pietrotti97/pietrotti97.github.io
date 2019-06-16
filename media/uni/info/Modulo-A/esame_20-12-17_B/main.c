#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct scacchiera
{
	char name[10];
	char colour[7];
	int x;
	int y;

}scacchiera_s;

int read_table(scacchiera_s sc[])
{
	int n=0,x, y;
	FILE *f;
	char colour[7];
	char name[10];
	f=fopen("scacchiera.txt","r");
	if(f==NULL)
	{
		printf("Sborat");
		return -1;
	}
	else
	{
		while(!feof(f))
		{
			fscanf(f,"%s %s %d %d",name,colour,&x,&y);
			strcpy(sc[n].name,name);
			strcpy(sc[n].colour,colour);
			sc[n].x=x;
			sc[n].y=y;
			n++;
		}
		return n;
	}
}
int read_move(scacchiera_s mossa[])
{
	FILE *f;
	int i=0;
	f=fopen("mossa.txt", "r");
	if(f==NULL)
	{
		printf("Sborat");
		return -1;
	}
	else
	{
		while(!feof(f))
		{
			fscanf(f,"%s %s %d %d",mossa[0].name, mossa[0].colour, &mossa[0].x,&mossa[0].y);
			i++;
		}
	}
	return i;
}
void print_struct(scacchiera_s mossa[], scacchiera_s sc[],int n,int m)
{
	int i;
	printf("\nScacchiera:\n\n");
	for(i=0;i<n;i++)
	{
		printf("%s %s %d %d\n", sc[i].name, sc[i].colour, sc[i].x, sc[i].y);
	}
	printf("\nMossa:\n\n");
	for(i=0;i<m;i++)
	{
		printf("%s %s %d %d\n", mossa[i].name, mossa[i].colour, mossa[i].x, mossa[i].y);
	}
}

int try(scacchiera_s mossa[], int k, scacchiera_s sc[], int i)
{
	if(strcmp(mossa[k].colour,sc[i].colour)==0) //verifico colori
	{
		//il colore è uguale
		return 1;
	}
	else //il colore è diverso
	{
		if((mossa[k].x == sc[i].x)&&(mossa[k].y == sc[i].y)) //verifico che x,y di sc e m siano uguali
		{
			//x,y di sc e m sono uguali
			return 0;
		}
		else
		{
			//x,y di sc e m sono diversi
			return 1;
		}
	}
}
void update(scacchiera_s mossa[], scacchiera_s sc[], int n, int k)
{
	printf("\n");
	printf("Il %s %s in %d %d, è stato killato da %s %s", sc[n].name, sc[n].colour, sc[n].x, sc[n].y,mossa[k].name, mossa[k].colour);
	strcpy(sc[n].name, mossa[k].name);
	strcpy(sc[n].colour, mossa[k].colour);
}
void do_something(scacchiera_s mossa[], scacchiera_s sc[],int s,int m)
{
	int i=0, k=0;
	while (i<s)
	{
		if(try(mossa, k, sc, i))
		{
			i++; //caso di return 1, avanzo nella scacchiera
		}
		else
		{
			//caso return 0, x,y sono uguali e colori diversi
			update(mossa, sc, i, k);
			print_struct(mossa,sc, s, m);
			i=999;
		}
	}
}
int main()
{
	int s, m;
	scacchiera_s sc[32], mossa[1];
	s=read_table(sc);
	m=read_move(mossa);
	//print_struct(mossa, sc, s, m);
	do_something(mossa, sc, s, m);
	return 0;
}
