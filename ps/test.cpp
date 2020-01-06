#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
	string str="abcde";
	for(auto r=str.rbegin(); r!=str.rend();r++)
        {
               cout<<*r<<" "<<endl;
        }
	return 0;
}
