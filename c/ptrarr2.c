#include<stdio.h>
#define MAX_SIZE 3
int main()
{
	int a, b, c;

	int *arr[MAX_SIZE] = {&a, &b, &c};

	int **newarr;
	newarr=arr;

	for(int i=0; i<MAX_SIZE; i++)
	{
		scanf("%d",*(newarr+i));
	}

	for(int i=0; i<MAX_SIZE; i++)
	{
		printf("%d",**(newarr+i));
	}

	return 0;
}
