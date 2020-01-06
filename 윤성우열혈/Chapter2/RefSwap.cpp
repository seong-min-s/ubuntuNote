#include <iostream>
using namespace std;
void SwapRef(int &num1, int &num2)
{
	int temp;
	temp = num1;
	num1 = num2;
	num2 = temp;
}
int main()
{
	int n = 1;
	int m = 2;
	cout<<m<<"(before),"<<n<<endl;
	SwapRef(23, 45);
	cout<<m<<"(after),"<<n<<endl;
	return 0;
}
