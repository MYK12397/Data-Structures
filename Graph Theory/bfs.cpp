#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N];
int d[N];
vector<int> bfstrav(int V,vector<int>adj[]){
	vector<int> bfs;
	vector<int> vis(V+1,0);
	for(int i=1;i<=V;i++){
		if(!vis[i]){
			queue<int> q;
			q.push(i);
			vis[i]=1;
			while(!q.empty()){
				int node=q.front();
				q.pop();
				bfs.push_back(node);

				for(auto u: adj[node]){
					if(!vis[u]){
						q.push(u);
						vis[u]=1;
					}
				}
			}
		}
	}
	return bfs;
}
int main() {
	int n, m;
	m = 5;
	int u, v;
	while (m--) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	memset(vis, 0, sizeof(vis));

	queue<int> Q;
	int src = 1;
	d[src] = 0;
	vis[src] = 1;
	Q.push(src);

	while (!Q.empty()) {
		u = Q.front();
		Q.pop();

		for (auto v : adj[u]) {
			if (vis[v] == 0) {
				d[v] = d[u] + 1;
				vis[v] = 1;
				Q.push(v);
			}
		}
	}

cout<<d[4];
	return 0;
}