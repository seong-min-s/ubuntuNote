#include<iostream>
using namespace std;

int main(void)
{

	int a=0;
	int *p=&a;

	cout<<"&a:"<<&a<<endl;
	cout<<"p:"<<p<<endl;
	cout<<"&p:"<<&p<<endl;
	return 0;
}
