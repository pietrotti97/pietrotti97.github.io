#include <stdio.h>
#include <stdlib.h>
#define gay1 "banco.bin"
#define gay2 "giocatore.bin"
typedef struct
{
	int num;
	char seme[7];
}carta_s;
int func(FILE *gamer,carta_s g[])
{
	int i=0;
	int a;
	a=sizeof(carta_s);
	i=fread(g,a,52,gamer);
	return i;
}
int read_files(carta_s gioca1[],carta_s gioca2[],int *gio1_el,int *gio2_el)
{
	FILE *gamer1;
	FILE *gamer2;
	gamer1=fopen(gay1,"rb");
	gamer2=fopen(gay2,"rb");
	if((gamer1 == NULL)||(gamer2==NULL))
	{
		printf("sborat\n");
		exit -1;
	}
	else
	{
		*gio1_el=func(gamer1, gioca1);
		*gio2_el=func(gamer2, gioca2);
	}
	fclose(gamer1);
	fclose(gamer2);
}
void printall(carta_s g[],int i)
{
	int n;
	for(n=0;n<i;n++)
	{
		printf("%8s %d\n", g[n].seme,g[n].num);
	}
}
int conta_punti(int carta,int *ax)
{
	int n;
	if((carta>10)&&(carta<14))
	{
		return 10;
	}
	else
	{
		if((carta>1)&&(carta<11))
		{
			n=carta;
			return n;
		}
		else
		{
			if(carta==1)
			{
				*ax=*ax+1;
				return 0;
			}
		}
	}
}
void asso(int *pt1,int ax)
{
	int try, d=0;
	if(ax<=1)
		{
			if(*pt1<11)
			{
				*pt1=*pt1+11;
			}
			else
			{
				*pt1++;
			}
		}
		else
		{
			try=*pt1+(11*ax);
			d=ax;
			while((try>21)||(d>0))
			{
				try=try-11;
				d--;
			}
			*pt1=try;
		}
}
void funct(carta_s gio1[], int gio1_el,carta_s gio2[],int gio2_el)
{
	int i;
	int pt1=0, pt2=0;
	int ax=0,el;
	int winner,pt;

	for(i=0;i<gio1_el;i++)
	{
		el=gio1[i].num;
		pt1=pt1+conta_punti(el,&ax);
	}
	asso(&pt1,ax);
	ax=0;
	for(i=0;i<gio2_el;i++)
	{
		el=gio2[i].num;
		pt2=pt2+conta_punti(el,&ax);
	}
	asso(&pt2,ax);
	if(pt1>pt2)
	{
		winner=1;
		pt=pt1;
	}
	else
	{
		if(pt1==pt2)
		{
			winner = 1;
			pt=pt1;
		}
		else
		{
			winner = 2;
			pt=pt2;
		}
	}
	printf("\n\nAnd the Winner is: giocatore %d, con %d punti!",winner,pt);
}
int main()
{
	int gio1_el, gio2_el;
	carta_s gio1[52],gio2[52];
	read_files(gio1,gio2, &gio1_el,&gio2_el);
	printf("\nGiocatore 1: \n");
	printall(gio1,gio1_el);
	printf("\nGiocatore 2: \n");
	printall(gio2,gio2_el);
	funct(gio1,gio1_el,gio2,gio2_el);
	return 0;
};
