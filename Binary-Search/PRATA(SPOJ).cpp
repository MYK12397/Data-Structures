#include<bits/stdc++.h>
#define inf  (int)1e18
#define MOD 1000000007
#define all(k) k.begin(),k.end()
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define repk(i,a,n) for(int i=a;i<=(n);i++)
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define mp make_pair
#define ll  long long
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vc vector<char>
#define vl vector<ll>
#define vvl vector<vl>
#define vi vector<int>
#define vvi vector<vi>
#define vc vector<char>
#define vs vector<string>
#define vpi vector<pi>
#define vpl vector<pl>
#define vvc vector<vc>
#define mi map<int,int>
#define ml map<ll,ll>
#define umap unordered_map<int, int>
#define int int64_t
using namespace std;
int prata(int rank, int time) {
	int cnt = 0, i = 1;
	while (rank * i <= time) {
		cnt++;
		time -= rank * i;
		i++;
	}
	return cnt;
}
bool is_possible(vi &a, int L, int P, int time) {
	int total_prata = 0;
	rep(i, 0, L) {
		total_prata += prata(a[i], time);
		if (total_prata >= P)
			return true;
	}
	return false;
}
void sol() {
	int P, L; cin >> P >> L; //p: numbers of prata ordered
	vi a(L);			//l: number of cooks
	rep(i, 0, L)cin >> a[i]; //ranks of each cook

	int l = 1, r = (a[0] * P * (P + 1)) / 2;
	int ans;
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (is_possible(a, L, P, m)) {
			ans = m;
			r = m - 1;
		}
		else
			l = m + 1;
	}
	cout << ans << "\n";
}




int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;


	for (cin >> t; t; t--)
		sol();


	return 0;
}