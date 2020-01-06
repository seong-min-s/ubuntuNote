#include<iostream>
using namespace std;
bool isOdd(int num);
int main()
{
	unsigned char a;
	unsigned char b = 1;
	unsigned char zero = 0;
	int count=0;

	for(a=1; a<33; a=a*2)
	{
		cout<<"a&(a-0x01) : "<<(a&(a-0x01))<<endl;
		if((a&(a-0x01)) == zero)
		{
			count++;
		}
	}
	cout << count << endl;

	for(int i = 0; i < 50; i++)
	{
		if(isOdd(i))
		{	
			cout<<i<<"is Even"<<endl;
		}
		else
		{
			cout<<i<<"is Odd"<<endl;
		}
	}
	
			

	return 0;
}
bool isOdd(int num)
{
	if(num==0)
	{
		return true;
	}
	
	while(num != 1)
	{
		if(num % 2 == 1)
		{
			return false;
		}
		num /=num;
	}

	return true;
}
