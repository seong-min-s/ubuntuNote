#include<iostream>
#include<vector>
using namespace std;
vector<int> slice(const vector<int> &v, int a, int b)
{
	return vector<int>(v.begin()+a, v.begin()+b);
}

int main()
{
	vector<int> a;
	for(int i=0; i<5; i++)
	{
		a.push_back(i);
	}
	vector<int> v(slice(a, 1, 3));

	for(vector<int>::iterator i=v.begin(); i!=v.end(); i++)
	{
		cout<<*i<<endl;
	}

	vector<int> b;
	for(vector<int>::iterator i=b.begin(); i!=b.end(); i++)
	{
		cout<<*i<<endl;
	}


	return 0;
}
