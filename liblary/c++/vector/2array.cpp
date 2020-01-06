#include<iostream>
#include<vector>

using namespace std;
int main(void)
{
	vector<vector<int>> v;
	vector<int>vs;

	for(int i=0; i<5; i++)
	{
		for(int j=0; j<5; j++)
		{

			vs.push_back(j);
		}
		v.push_back(vs);
		vs.erase(vs.begin(), vs.end());
	}
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<5; j++)
		{
			cout<<v[i][j];
		}
		cout<<endl;
	}

	return 0;
}
