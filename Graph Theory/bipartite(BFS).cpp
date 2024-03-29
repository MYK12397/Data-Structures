#include<bits/stdc++.h>
using namespace std;

bool bipartitebfs(int v,vector<int>adj[],int color[]){
	queue<int>q;
	q.push(v);
	color[v]=1;
	while(!q.empty()){
	int node= q.front();
	q.pop();
	for(auto it: adj[node]){
	if(color[it]==-1){
	color[it]=!color[node];
	q.push(it);
	}
	else if(color[it]==color[node])
	return false;
	}
	}
	return true;
}
bool isBipartite(vector<int> adj[],int n){
	int color[n];
	memset(color,-1,sizeof color);

	for(int i=0;i<n;i++){
	if(color[i]==-1)
	if(!bipartitebfs(i,adj,color))
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