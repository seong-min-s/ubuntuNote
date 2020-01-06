#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> adj;//그래프의 인접리스트 표현
vector<bool> visited;//각 정점을 방문했는지의 여부를 나타낸다.
void dfs(int here) {
	cout<<"DFS visits"<<here<<endl;
	visited[here]=true;
	//모든 인접 정점을 순회하면서
	for(int i=0; i<adj[here].size(); ++i)
	{
		int there=adj[here][i];
		if(!visited[there]){
			dfs(there);
	//		cout<<here<<"_is";
		}
	}
}
void dfsAll(){
	//visited를 모두 false로 초기화한다.
	visited=vector<bool>(adj.size()+1, false);
	for(int i=1; i<adj.size(); ++i)
		if(!visited[i])
			dfs(i);
}
int main()
{
	int n,m,v;
	int x,y;

	cin>>n>>m>>v;
	adj=vector<vector<int>>(n+1,vector<int>());//그래프의 인접리스트 표현
	//visited=vector<bool>(adj.size()+1, false);


	for(int i=0; i<m; i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
	}
	//cout<<adj.size()<<","<<endl;	
	dfsAll();


	return 0;
}
