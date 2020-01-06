#include<iostream>
#include<queue>
#include<list>
#include<string>
using namespace std;

int main(void)
{
	string str[3]={"a","b","c"};
	list<string> mylist(str,str+sizeof(str)/sizeof(string));
	
	queue<int,list<string>> q(mylist);

	q.push("d");
	cout<<q.size();
	//cout<<q.front();

	return 0;
}
