#include<iostream>
#define ENTER 1
#define F1 2
#define F2 4
#define F3 8
using namespace std;

int main(void)
{
	unsigned char byte = 0;

	byte = byte | (F1 | F2);

	cout<<(int)byte<<endl;
	
	byte = byte & (~F1);

	cout<<(int)byte<<endl;

	return 0;
}
