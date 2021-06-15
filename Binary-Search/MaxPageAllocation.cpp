#include<bits/stdc++.h>
using namespace std;
bool isval(int a[], int n, int k, int m) {
	int student = 1;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (sum > m) {
			student++;
			sum = a[i];
		}
		if (student > k)
			return false;
	}
	return true;
}
int Page_Allocation(int a[], int n, int k) {
	int l = *max_element(a, a + n);
	int r = 0, res = -1;
	for (int i = 0; i < n; i++)r += a[i];
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (isval(a, n, k, m))
		{
			res = m;
			r = m - 1;

		}
		else
			l = m + 1;
	}
	return res;
}

int main()
{
	// int a[] = {10, 20, 30, 40};
	int a[] = {12, 34,67, 90};

	int n = sizeof(a) / sizeof(a[0]);
	int k = 2;
	cout << Page_Allocation(a, n, k);
	return 0;
}