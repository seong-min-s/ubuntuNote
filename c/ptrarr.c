#include<stdio.h>

int main()
{
	int a, b, c;
	int *arr[3];//int *arr[3]={&a,&b,&c}; 도 가능하다.

	arr[0]=&a;
	arr[1]=&b;
	arr[2]=&c;


	printf("3개의 정수 입력 : ");
	//scanf("%d", arr[0]);
	//scanf("%d", arr[1]);
	//scanf("%d", arr[2]);

	scanf("%d",*(arr+0));
	scanf("%d",*(arr+1));
	scanf("%d",*(arr+2));

	//printf("%d\n",*arr[0]);
	//printf("%d\n",*arr[1]);
	//printf("%d\n",*arr[2]);

	printf("%d\n",**(arr+0));
	printf("%d\n",**(arr+1));
	printf("%d\n",**(arr+2));
	return 0;
}
