#include<iostream>
using namespace std;
int main()
{
	const int a = 39;

	const int *p = &a;

	const int &k = *p;

	cout << k <<","<<*p;
	
	return 0;
}
