#include<stdio.h>

int main()
{
	char s[100];
	//scanf("%s",s);
	fgets(s,100,stdin);
	printf("%s\n",s);
	return 0;
}
