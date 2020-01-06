#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str ="10:46:30";

	string hour=str.substr(0,2);
	string min =str.substr(3,2);
	string sec =str.substr(6,2);

	size_t pos = str.find("46");

	string p=str.substr(pos);
	cout<<hour<<"시"<<min<<"분"<<sec<<"초"<<endl;
	cout<<"pos : "<<pos<<endl;
	int q = stoi(str,&pos);
	cout<<"pos : "<<pos<<endl;//문자열에서 마지막 숫자의 인덱스
	cout<<q<<endl;

	return 0;
}

