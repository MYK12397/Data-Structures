#include<bits/stdc++.h>
using namespace std;
bool bipartitedfs(int src,vector<int>adj[],int color[]){
	
	for(auto it: adj[src]){
		if(color[it]==-1){
			color[it]=!color[src];
			if(!bipartitedfs(it,adj,color))
				return false;
		}
		else if(color[it]==color[src])
			return false;
	}
	return true;
}

bool isBipartite(vector<int> adj[],int n){
	int color[n];
	memset(color,-1,sizeof color);

	for(int i=0;i<n;i++){
	if(color[i]==-1)
	if(!bipartitedfs(i,adj,color))
	return false;
	}

	return true;
}
int main(){
	int n,m;cin>>n>>m;
	vector<int> adj[n];
	for(int i=0;i<m;i++){
	int u,v;cin>>u>>v;
	adj[u].push_back(v);
	adj[v].push_back(u);
	}
	if(isBipartite(adj,n))
	cout<<"yes";
	else
	cout<<"no";
	cout<<"\n";

	return 0;
}