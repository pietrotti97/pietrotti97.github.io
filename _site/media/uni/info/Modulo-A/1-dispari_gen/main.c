#include <stdio.h>
#include "dispari.h"
int main(void)
{
	int i;
	for(i=1;i<10;i++)
	{
		printf("%d", prossimoDispari());
	}
	return 0;
}
