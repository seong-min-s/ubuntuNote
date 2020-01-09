#include<iostream>
using namespace std;
int cache[100] = {-1,};
int fibonacciRecursive(int n)
{

	if( n==0 || n==1 )
	{
		return 1;
	}
	else if( cache[n] != -1)
	{
		return cache[n];
	}
	else
	{
		cache[n] = fibonacciRecursive(n-2)+fibonacciRecursive(n-1);
		return cache[n];
	}

}
int main(void)
{
	int result;
	for(int i = 0; i< 100; i++)
	{
		cache[i] = -1;
	}
	result = fibonacciRecursive(3);
	cout << result;
	return 0;
}


