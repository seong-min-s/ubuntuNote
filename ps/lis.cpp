#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main()
{
	FILE *fp = fopen("test.txt", "a+");

	int m=0,n=0,k=0,i=0,j=0;
	int total=0;
	total=fgetc(fp)-48;
	cout << a;

	while(total>0){
		m=fgetc(fp)-48;
		n=fgetc(fp)-48;
		int *a=new int[m];
		int *b=new int[n];
		for(i=0; i<m; i++)
		{
			a[i]=fgetc(fp)-48;
		}
		for(j=0; j<n; j++)
		{
			b[i]=fgetc(fp)-48;
		}
		while(k<m && k<n)
		{
			if(
		}
		for(int idx_result=k; i<m; i++)
		{
			result[idx_result] = a[i];
		}
		for(int idx_result=k; i<m; i++)
		{
			result[idx_result] = a[i];
		}
		delete []a;
		delete []b;

	}
	fclose(fp);
	return 0;
}
