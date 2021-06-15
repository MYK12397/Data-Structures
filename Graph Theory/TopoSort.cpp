#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+ 5;
vector<int> adj[N];
vector<bool> vis(N);

void toposort(int node,stack<int> &s){
	vis[node]=1;
	for(auto nbr: adj[node]){
	if(!vis[nbr]){
	toposort(nbr,s);
	}
	}

	s.push(node);

}

int main()
{
	int n,m;cin>>n>>m;

	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
	}

	vector<int> res;
	stack<int> s;
	for(int i=1;i<=n;i++){ //for 0-based index , start with 0 to n-1 (i<n);
		if(!vis[i])
		toposort(i,s);
	}
	while(!s.empty()){
		res.push_back(s.top());
		s.pop();
	}
	if(res.size()==n)
	for(auto k: res)
		cout<<k<<" ";
	else
		cout<<"Sandro fails.";

return 0;
}
