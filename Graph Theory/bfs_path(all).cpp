#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("trapv")
#pragma GCC target("sse4")

#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define all(k) k.begin(),k.end()
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define repk(i,a,n) for(int i=a;i<=(n);i++)
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define mp make_pair
#define ll  long long
#define ull unsigned long long
#define pi pair<int,int>
#define vc vector<char>
#define vs vector<string>
#define vi vector<int>
#define vvi vector<vi>
#define vc vector<char>
#define vpi vector<pi>
#define vvc vector<vc>
#define mi map<int,int>
#define umap unordered_map
// #define int int64_t
#define fi first
#define se second
int modint(int x, int n, int mod) {
	int ans = 1;
	while (n) {
		if (n & 1)
			ans = ans * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return ans;
}
const int nn=1e5;
vvi adj;
int n,m;

vi bfs_dist(int src){

	vector<bool> vis(n,0);
	queue<int>q;
	vector<int> d(n+1,-1);

q.push(src);
vis[src]=1;
d[src]=0;

while(!q.empty()){

	int u=q.front();
	q.pop();
// cout<<u<<' ';
for(auto k: adj[u]){
	if(!vis[k]){
		vis[k]=1;
		d[k]=d[u]+1;
		q.push(k);
	}
}
}
return d;

}
vi bfs_par(int src){
	vector<bool> vis(n,0);
	queue<int>q;
	vector<int> par(n+1,-1);
q.push(src);
vis[src]=1;


while(!q.empty()){

	int u=q.front();
	q.pop();
// cout<<u<<' ';
for(auto k: adj[u]){
	if(!vis[k]){
		vis[k]=1;
		par[k]=u;
		q.push(k);
	}
}
}
return par;

}
void print_path(int cur,vi &d,vi &p){
	int i=cur;
	if(d[cur]==-1)
		cout<<i<<"\t"<<"No Path\n";
	else{
		vi path;
		while(cur!=-1)
			path.pb(cur),cur=p[cur];

		reverse(all(path));

		cout<<i<<"\t";
		for(int i:path)
			cout<<i<<" ";

		cout<<'\n';
	}
}
void sol() {

cin>>n>>m;
adj.resize(n+1);

rep(i,0,m){
	int u,v;cin>>u>>v;
	adj[u].pb(v);
	adj[v].pb(u);
}
vi d=bfs_dist(1);
vi p=bfs_par(1);

repk(i,1,n)
print_path(i,d,p);	



}

int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	
	// for (cin >> t; t; t--)
	sol();


	return 0;
}
