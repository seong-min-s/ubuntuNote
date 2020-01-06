#include <iostream>
#include <string.h>
using namespace std;
char *MakeStrAdr(int len)
{
	char *str = new char[len];
	return str;
}
int main(){
	char *name = MakeStrAdr(20);
	strcpy(name, "I am so happy");
	cout<<name<<endl;
	delete []name;
	return 0;
}
