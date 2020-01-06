#include <iostream>
using namespace std;
void SwapPointer(int *(&p), int *(&q))
{
	int *temp = p;
	p = q;
	q = temp;
}
int main()
{
	int num1=5;
	int *ptr1=&num1;
	int num2=10;
	int *ptr2=&num2;
	cout << "ptr1 address :" << ptr1 << "," << "ptr2 address :" << ptr2 << endl;
	SwapPointer(ptr1, ptr2);
	cout << "ptr1 address :" << ptr1 << "," << "ptr2 address :" << ptr2 << endl;
	return 0;
}

