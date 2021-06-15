#include<bits/stdc++.h>
using namespace std;
struct job {
	int start, finish, profit;
};
bool comp(job s1, job s2) {
	return (s1.finish < s2.finish);
}
int bs(job jobs[], int id) {
	int l = 0, r = id - 1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (jobs[m].finish <= jobs[id].start) {
			if (jobs[m + 1].finish <= jobs[id].start)
				l = m + 1;
			else
				return m;
		}
		else
			r = m - 1;
	}
	return -1;
}
int maxprofit(job a[], int n) {
	sort(a, a + n, comp);
	int dp[n];
	dp[0] = a[0].profit;
	for (int i = 1; i < n; i++) {
		int include_profit = a[i].profit;
		int l = bs(a, i);
		if (l != -1)
			include_profit += dp[l];
		dp[i] = max(dp[i - 1], include_profit);
	}
	return dp[n - 1];
}
int main()
{
	job a[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
	job b[] = {{1, 4, 3}, {2, 6, 5}, {4, 7, 2}, {6, 7, 6}, {5, 9, 4}, {7, 10, 8}};
	int n = sizeof(a) / sizeof(a[0]);
	cout << maxprofit(b, n);

	return 0;
}