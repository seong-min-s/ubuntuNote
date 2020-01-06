#include<iostream>
#include<vector>

using namespace std;

int main(void)
{

	vector<int> v(5,0);

	for(int i=0; i<5; i++)
	{
		v[i]=i;
	}
	v.erase(v.begin()+2);
	for(int i=0; i<v.size(); i++)
	{
		cout<<v[i]<<" ";
	}	
	
	
	return 0;
}
