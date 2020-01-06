#include<string>
#include<iostream>
#include<cstdio>
using namespace std;

int main(void)
{
	//c-style
/*	
 	char c_str[256];
	cin.getline(c_str,256,'2');

	cout<<"c-style is "<<c_str<<endl;

	for(int i=0; i<5; i++)
	{
		cout<<(int)c_str[i]<<endl;
	}
*/
	int a;
	cin>>a;
	string str;
	cin>>str;

	cout<<str;

	//c++ style
	//
/*
	string str;
	getline(cin,str,'\n');
	for(int i=0; i<str.size()+1; i++)
	{
		cout<<str[i]<<endl;
	}

	char cs[10];
	scanf("%s",cs);
	for(int i=0; i<4; i++)
	{
		cout<<(int)cs[i]<<endl;
	}
	
	char a[10];
	char b[10];
	char c[10];
	int d;
	cin>>a;
	cout<<a<<endl;
 	cin>>b;
	cout<<b<<endl;
	cin>>d;
	cout<<c;
	*/
	return 0;
}
