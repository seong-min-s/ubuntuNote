#include<iostream>
#include<vector>
using namespace std;
void dfs(int sp, int arr[][5]);
int arr[5][5]={{0,},};
bool visited[5]={0,};

int main()
{
	int n,m,v;
	int x,y;
	cin>>n>>m>>v;
	for(int i=0; i<5; i++)
	{
		cin>>x>>y;
		arr[x][y]=1;
	}
	dfs(v,arr);
	return 0;
}

void dfs(int sp, int arr[][5]){
	cout<<sp<<" visit";
	visited[sp]=1;
	for(int i=0; i<5; i++)
	{
		if(arr[sp][i]==1 && visited[i]==0)
		{
			dfs(i,arr);
		}
	}
}

