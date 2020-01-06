#include<string>
#include<iostream>

using namespace std;

int main(void)
{
	string str;

	cout<<"size(): "<<str.size()<<endl;
	str=str+"hello";
	//cin.ignore(256,' ');	
	cout<<"str:"<<str;

	return 0;
}
