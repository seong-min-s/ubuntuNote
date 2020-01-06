#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(void)
{
	vector<int> v;
	for(int i=0; i<10; i++)
	{
		v.push_back(i);
	}

	stack<int,vector<int>> s(v);

	while(!s.empty())
	{
		cout<<s.top();
		s.pop();
	}

	return 0;
}
