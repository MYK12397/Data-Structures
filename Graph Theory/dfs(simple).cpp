#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("trapv")
#pragma GCC target("sse4")

#include<bits/stdc++.h>
#define inf  (int)1e18
#define all(k) k.begin(),k.end()
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define repk(i,a,n) for(int i=a;i<=(n);i++)
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define ll  long long
#define ull unsigned long long
#define pci pair<char,int>
#define vc vector<char>
#define vs vector<string>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vb vector<bool>
#define vpc vector<pci>
#define vvc vector<vc>
#define mi map<int,int>
#define mset map<string,set<char>>
#define umap unordered_map
// #define int int64_t
using namespace std;
#define fi first
#define se second
int st[200];
int ft[200];
vi adj[10000];
int t=1;
vector<bool> vis(10000, 0);
void dfs(int k) {
	st[k]=t++;
	vis[k] = 1;
	for (auto p : adj[k])
	{
		if (!vis[p])
			dfs(p);
	}
	ft[k]=t++;
}
// 1 0 2 3 1 3 2 1
void sol() {

	int v = 4, e; //v is vertices(nodes) & e->edges

	while (v--) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// int p, q; cin >> p >> q;//can you go from p to q?

	dfs(1);
	// if (vis[q])
	// 	cout << "YES";
	// else
	// 	cout << "NO";

	rep(i, 0, 5) {//cout<<i<<" "<<st[i]<<" "<<ft[i]<<" ";
	
		for(auto k: adj[i])
			cout<<k<<" ";

		cout<<endl;
	}
}
int32_t main() {


	int t = 1;


	// for (cin >> t; t; t--)
	sol();


	return 0;
}
