#include<bits/stdc++.h>
using namespace std;
bool cycleCheck(int s,int V,vector<int> adj[],vector<int> &vis){
	queue<pair<int,int>> q;
	q.push({s,-1});

	while(!q.empty()){
	int node= q.front().first;
	int par= q.front().second;
	q.pop();

	for(auto u: adj[node]){
	if(!vis[u]){
	vis[u]=true;
	q.push({u,node});
	}
	else if(u!=par)
	return true;
	}

	}
	return false;
}

bool iscycle(int V,vector<int>adj[]){
	vector<int> vis(V,0);

	for(int i=0;i<V;i++){
	if(!vis[i]){
	if(cycleCheck(i,V,adj,vis))
	return true;
	}
	}
	return false;
}

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

	if(iscycle(V,adj))
	cout<<"1";
	else
	cout<<"0";

	cout<<'\n';

return 0;
}