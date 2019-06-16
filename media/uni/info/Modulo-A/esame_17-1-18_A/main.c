#include <stdlib.h>
#include <stdio.h>
typedef struct delitto
{
	char type[20];
	int x;
	int y;
}delitto_t;
typedef char matrix[10][10];

int read_text(delitto_t ting[])
{

	int k, x, y, i=0;
	char tipo[20];

	FILE *f;
	f=fopen("delitti.txt" , "r");
	if(f==NULL)
	{
		printf("sborat\n Terminated");
		return 1;
	}
	else
	{
		printf("K\n");
		while(!feof(f))
		{
			fscanf(f,"%s %d %d",&tipo, &x, &y);
			strcpy(ting[i].type,tipo);
			ting[i].x=x;
			ting[i].y=y;
			i++;
		}
	}
	fclose (f);
	return i;
}

void read_struct(delitto_t ting[], int i)
{
	int n=0;
	printf("Lettura Omicidi\n");
	for(n=0;n<i;n++)
	{
		printf("%s,%d,%d\n", ting[n].type, ting[n].x, ting[n].y);
	}
	printf("\nEnd\n\n");
}

void mke_map(delitto_t ting[], int i, matrix M)
{
	int n;
	for(n=0;n<i;n++)
	{
		if(strcmp(ting[n],"Omicidio")==0)
		{
			M[ting[n].x][ting[n].y]='*';
		}
	}
}
void print_map(matrix M)
{
	int r=0, c=0;
	//matrice 10x10
	printf("Matrix Print:\n\n");
	for(r=0;r<10;r++)
	{
		for(c=0;c<10;c++)
		{
			if(M[c+1][r+1]=='*')
			{
				printf("x ");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	printf("\nEnd!\n");
}
int main()
{
	delitto_t ting[100];
	int k;
	matrix M[10][10];
	k=read_text(ting);
	read_struct(ting, k);
	mke_map(ting, k, M);
	print_map(M);
	return 0;
}
