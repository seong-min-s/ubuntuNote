#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int tc;
	int size;
	int get;
	cin>>tc;
	while(tc--)
	{
		cin>>size;
		vector<int> preorder(size);
		vector<int> inorder(size);

		for(int i=0; i<size; i++)
		{
			cin>>get;
			preorder.push_back(get);	
		}

		for(int i=0; i<size; i++)
		{
			cin>>get;
			inorder.push_back(get);	
		}

		for(int i=0; i<size; i++)
		{
			cout<<inorder.at(i)<<endl;	
		}
	}
	return 0;
}
