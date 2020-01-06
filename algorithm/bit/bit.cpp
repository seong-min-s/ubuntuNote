#include<iostream>

using namespace std;

int main(void)
{
	int a = 240;
	
	for(int i=31; i>=0; i--)
	{
		cout << ((a>>i)&1);
		if(i%4==0)
			cout << " ";
	}
	cout<<endl;



	return 0;
}
