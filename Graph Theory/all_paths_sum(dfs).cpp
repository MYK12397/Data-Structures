#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000000
vector<vector<pair<int,int>>> adj;
int64_t ans =0;
int n;

//Approach
// Start the depth first search from some vertex of the tree. Consider an 
// edge (u, v) of a tree with weight w. Let the number of vertices in the subtree with the root v be equal to c. 
// Then the tree contains c vertices on one side of the edge, and n – c vertices on the other. 
// The edge (u, v) appears in c * (n – c) different paths. Therefore, 
// the contribution of this edge to the sum of the lengths of all paths is c * (n – c) * w.
// It remains to iterate through all the edges with a depth first search 
// and sum their contribution to the total length.

/*
test case:
3
1 2 1
1 3 3



The edge (1, 2) of weight 1 belongs to two paths:

·        1 – 2;

·        2 – 1 – 3;

Its contribution to the total sum is 1 * 2 * 1 = 2.

*/



int64_t dfs(int src,int par= -1){
	int cnt =1, c;

	for(auto k: adj[src]){
	int to = k.first;
	int weight = k.second;
	if(to != par){

	c= dfs(to,src);
	ans = (ans + 1ll*c*(n-c)*weight)%MOD;
	cnt += c;
	}
	}
return cnt;
}

int main()
{
	
	cin>>n;

	adj.resize(n + 1);

	for(int i=0;i<n-1; i++){
	int u, v, wt;
	cin>>u>>v>>wt;
	adj[u].push_back({v,wt});
	adj[v].push_back({u,wt});
	}

	dfs(1);

	cout<<ans;

	return 0;

	
}