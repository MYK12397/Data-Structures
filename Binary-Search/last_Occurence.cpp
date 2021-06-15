#include<iostream>
using namespace std;
int last_Occurrence(int a[], int n, int x) {
	int l = 0, r = n - 1, res = -1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (a[m] == x)
		{	res = m;
			l = m + 1;
		}
		else if (a[m] > x) {
			l = m + 1;
		}
		else
			r = m - 1;
	}
	return res;
}

int main() {
	int n = 7;
	int a[] = {2, 10, 10, 10, 10, 10, 10};
	int x = 10;

	cout << last_Occurrence(a, n, x);
	return 0;
}