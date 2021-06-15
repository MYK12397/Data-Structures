#include<bits/stdc++.h>
using namespace std;
const int N= 1e5 + 5;
vector<int> adj[N];

vector<int> topoSort_Bfs(int n){
	queue<int> q;

	vector<int> indegree(n+1,0);

	for(int i=0;i<n;i++)
	{
		for(auto k: adj[i])
		{
			indegree[k]++;
		}
	}

	for(int i=0;i<n;i++)
		if(indegree[i]==0)
			q.push(i);


	vector<int> topo;
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		topo.push_back(node);
		for(auto k: adj[node])
		{
			indegree[k]--;
			if(indegree[k] == 0)
			q.push(k);
		}
	}

return topo;
}
int main()
{
	int n,m;cin>>n>>m;

   for(;m;m--){
    int src,dest; cin>>src>>dest;
    adj[src].push_back(dest);
 
   }

vector<int> res =topoSort_Bfs(n);

for(auto k: res)
  cout<<k<<" ";


  return 0;
}

