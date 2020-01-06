#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
string temp(" ");

string code[9]={ "0001101","0011001","0010011","0111101","0100011","0110001","0101111","0111011","0001011"};
int main()
{
	int tc,m,n;
	int c;
	int count;
	vector<stack<int>> v;
	stack<int> row;
	cin>>tc;
	cin.ignore(256,'\n');
	for(int i=0; i<tc; i++)
	{
		cin>>m>>n;
		for(int y=0; y<m; y++)
		{
			for(int x=0; x<n; x++)
			{
				cin>>c;
				row.push(c);
			}
			v.push_back(row);
			for(; !v[i].empty(); )
			{
				cout<<v[i].top();
				v[i].pop();
			}
		}
		v.erase(v.begin(),v.end());
	}
	return 0;    
}
