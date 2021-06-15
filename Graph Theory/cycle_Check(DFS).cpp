#include<bits/stdc++.h>
using namespace std;
bool dfsCycle(int node, int parent, vector<int> &vis,vector<int> adj[]){
	vis[node]=1;
	for(auto u: adj[node]){
	if(!vis[u]){
	if(dfsCycle(u,node,vis,adj))
		return true;
	}
	else if(u!=parent)
	return true;

	

	}
	return false;
}
bool isCycle(int v,vector<int> adj[]){
	vector<int> vis(v,0);
	for(int i=0;i<v;i++){
	if(!vis[i]){
	if(dfsCycle(i,-1,vis,adj))
	return true;
	}
	}
	return false;
}
//tc
// 4 3
// 0 1
// 1 2
// 2 3

int main()
{
	
	int V, E;cin>>V>>E;

	vector<int>adj[V];
	for(int i=0;i<E;i++)
	{
	int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if(isCycle(V,adj))
	cout<<"1";
	else
	cout<<"0";

	cout<<'\n';
}