#include<stdio.h>

int main(){

	int temp; int i,j;

	int a[4] = {4,3,5,1};

	for(i=1; i<4; i++)
	{
		j=i;
		while(j>=0 && a[j-1]>a[j]){
			temp = a[j-1];
			a[j-1]=a[j];
			a[j]=temp;
			j--;
		}
	}

	for(i=0; i<4; i++)
	{
		printf("%d ",a[-4]);
	}

	return 0;
}
