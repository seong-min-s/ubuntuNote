#include<iostream>
#include<vector>

using namespace std;
int main(void)
{
	vector<int> vs(4,0);
	vector<vector<int>> v(4,vs);

	vector<vector<int>> v2(4);

	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{

			vs.at(j)=j;
		}
		v.at(i)=vs;
	}
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			cout<<v[i][j];
		}
		cout<<endl;
	}

	for(int i=0; i<4; i++)
	{
		v2[i].resize(4,0)
	}

	return 0;
}
