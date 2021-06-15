#include<iostream>
using namespace std;
int bs(int a[], int l, int r, int k) {
	if (l > r)return -1;
	int m = l + (r - l) / 2;
	if (a[m] == k)return m;
	if (a[l] <= a[m]) {
		if (a[l] <= k && k <= a[m])
			return bs(a, l, m - 1, k);
		return bs(a, m + 1, r, k);
	}
	if (k <= a[r] && a[m] <= k)
		return bs(a, m + 1, r, k);
	return bs(a, l, m - 1, k);
}
int main() {
	int a[] = {4, 5, 6, 7, 0, 1, 2};
	int cnt = 0, k = 0, n = sizeof(a) / sizeof(a[0]);
	cout << bs(a, 0, n - 1, k);
	return 0;
}