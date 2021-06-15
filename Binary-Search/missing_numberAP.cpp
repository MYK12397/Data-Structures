#include<bits/stdc++.h>
using namespace std;
int main() {
	int a[] = {2, 4, 8, 10, 12, 14};
	int n = sizeof(a) / sizeof(a[0]);

	int diff = (a[n - 1] - a[0]) / n;
	int missing_number;
	int l = 0, r = n - 1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (a[m] != (a[0] + m * diff)) {
			missing_number = a[0] + m * diff;
			r = m - 1;
		}
		else
			l = m + 1;
	}
	cout << missing_number;
	return 0;

}