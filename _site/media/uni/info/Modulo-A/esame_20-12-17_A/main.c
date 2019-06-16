#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int func()
{
	FILE *inferno;
	FILE *mex;
	int c, n, i;
	int inf_c, inf_p;
	char parola[20];
	bool find;
	inferno=fopen("inferno.txt","r");
	mex=fopen("messanahggio.txt","r");
	if((inferno == NULL) || (mex==NULL))
	{
		printf("Sborat\n");
		return -1;
	}
	else
	{
		while(!feof(mex))
		{
			fscanf(mex,"%d %d\n", &c, &n);

			while((!feof(inferno))&&(!find))
			{
				fscanf(inferno,"%d %d %s",&inf_c, &inf_p, parola);
				if((inf_c==c) && (inf_p == n))
				{
					printf("%s\t", parola);
					i++;
					find = true;
					rewind(inferno);
				}
			}
			if(find == true)
			{
				find = false;
			}
		}

	}
	fclose(mex);
	fclose(inferno);
	return i;
}
int main()
{
	int n;
	n=func();

	return 0;
}
