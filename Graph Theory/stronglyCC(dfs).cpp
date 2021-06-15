#include<bits/stdc++.h>
using namespace std;
int v, e;

void dfs(int i, bool *vis, vector<int> ad[]) {
	vis[i] = true;
	for (auto k : ad[i])
	{
		if (!vis[k])
			dfs(k, vis, ad);
	}
}
int main()
{
	cin >> v >> e; //v is vertices(nodes) & e->edges
	vector<int> ad[v + 1];
	for (int i = 1; i <= v; i++) {
		int a, b; cin >> a >> b;
		ad[a].push_back(b);
		ad[b].push_back(a);
	}
	int cnt = 0;
	bool vis[v + 1];
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= v; i++) {
		if (!vis[i]) {
			cnt++;
			dfs(i, vis, ad);
		}
	}
	cout << cnt << "\n";

	return 0;
}
