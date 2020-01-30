#include<stdlib.h>
#include<stdio.h>

int main()
{
	int *p = NULL;
	int i;
	p = (int*)malloc(sizeof(int)*4);

	for(i=0; i<4; i++)
	{
		//p[i] = i;
		scanf("%d",&p[i]);
	}

	for(i=0; i<4; i++)
	{
		printf("p[%d]: %d\n",i,p[i]);
	}

	free(p);
	return 0;
}
