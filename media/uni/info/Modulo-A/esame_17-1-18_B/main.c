#include <stdlib.h>
#include <stdio.h>
typedef struct delitto
{
	char type[20];
	char name[20];
	int num;
}delitto_t;
typedef struct rubrica
{
	char via[20];
	int num;
	int x;
	int y;
}rubrica_i;
typedef char matrix[10][10];

int read_kill(delitto_t ting[])
{

	int k, x, num, i=0;
	char tipo[20], name[20];
	FILE *f;
	f=fopen("misfatti.txt" , "r");
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
			fscanf(f,"%s %s %d",tipo, name, &num);
			strcpy(ting[i].type,tipo);
			strcpy(ting[i].name, name);
			ting[i].num=num;
			i++;
		}
	}
	fclose (f);
	return i;
}
int read_address(rubrica_i address[])
{

	int k, x, y, num, i=0;
	char via[20];
	FILE *f;
	f=fopen("indirizzi.txt" , "r");
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
			fscanf(f,"%s %d %d %d",via,&num,&x,&y);
			strcpy(address[i].via,via);
			address[i].num=num;
			address[i].x=x;
			address[i].y=y;
			i++;
		}
	}
	fclose (f);
	return i;
}
void read_struct(delitto_t ting[], int i, rubrica_i address[], int l)
{
	int n=0;
	printf("\nLettura Misfatti:\n\n");
	for(n=0;n<i;n++)
	{
		printf("%s,%s,%d\n", ting[n].type, ting[n].name, ting[n].num);
	}
	printf("\n\nLettura Indirizzi:\n\n");
	for(n=0;n<l;n++)
	{
		printf("%s,%d,%d, %d\n",address[n].via, address[n].num, address[n].x, address[n].y );
	}
	printf("\nEnd\n\n");
}
void mke_map(int x, int y, matrix M)
{
	M[x][y]='*';
}
int compare(delitto_t ting[], int n, rubrica_i address[], int o)
{
	if((strcmp(ting[n].name,address[o].via)==0) && (ting[n].num==address[o].num))
			return 1;
		else
			return 0;
}
void findall(delitto_t ting[], int i, rubrica_i address[], int l, matrix M)
{
	int n=0, o=0, a, b, true=5, en=0;;
	for(n=0;n<i;n++)
	{
		if(strcmp(ting[n].type, "Omicidio")==0)
		{
			for(o=0;o<l;o++)
			{
				if(compare(ting, n, address, o)==1)
				{
					a=address[o].x;
					b=address[o].y;
					mke_map(a, b, M);
					o=l+2;
				}
			}
		}
	}
	printf("findall_ended\n");
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
	rubrica_i address[200];
	int k, l;
	matrix M[10][10];
	k=read_kill(ting);
	l=read_address(address);
	//read_struct(ting, k, address, l);
	findall(ting, k, address, l, M);
	print_map(M);
	return 0;
}
