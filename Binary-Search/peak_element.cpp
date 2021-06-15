#include<iostream>
using namespace std;
int peak_element(int a[], int n) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (m > 0 && m < n - 1) {
			if (a[m - 1] < a[m] && a[m] > a[m + 1])
				return m;
			else if (a[m - 1] > a[m])
				r = m - 1;
			else if (a[m + 1] > a[m])
				l = m + 1;
		}
		else if (m == 0)
		{
			if (a[0] > a[1])
				return 0;
			else
				return 1;
		}
		else if (m == n - 1) {
			if (a[m] > a[n - 2])
				return n - 1;
			else
				return n - 2;
		}
	}

	return -1;
}
int main()
{
	int a[] = {1, 4,8, 3, 2};
	int n = sizeof(a) / sizeof(a[0]);
	cout << peak_element(a, n);

	return 0;
}