#include<stdio.h>

int main()
{
	int num=0;
	char arr[4];
	scanf("%s", arr);
	for(num=0; num<5; num++)
	printf("%d\n",*(arr+num));
	return 0;
}
