#include<iostream>
using namespace std;

int countRotation(int a[], int n) {
	if (a[0] < a[n - 1])return 0;
	int l = 0, r = n - 1;
	int  m;
	while (l <= r) {
		if (a[l] < a[r])return l;//for single element
		m = l + (r - l) / 2;
		int prev = (m + n - 1) % n;
		int nex = (m + 1) % n;//no need to check next element because m would be smaller tha
		//than next element

		if (a[m] <= a[prev] && a[m] <= a[nex])
			return m; //for right rotated array, return n-m
		else if (a[m] >= a[l])
			l = m + 1;
		else if (a[m] <= a[r])
			r = m - 1;

	}
	return -1;

}
int main()
{
	int a[] = {5, 1, 2, 3, 4};
	int cnt = 0, k, n = sizeof(a) / sizeof(a[0]);

	cout << countRotation(a, n);
	return 0;
}
