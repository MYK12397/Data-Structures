#include<iostream>
using namespace std;
int nearlysortary(int a[], int n, int k) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (a[m] == k)return m;
		else if (m - 1 >= l && a[m - 1] == k)return m - 1;
		else if (m + 1 <= r && a[m + 1] == k)return m + 1;
		else if (a[m] > k)
			r = m - 2;
		else
			l = m + 2;
	}
	return -1;
}
int main()
{
	int a[] = {5, 10, 30, 20, 40};
	int n = sizeof(a) / sizeof(a[0]), k = 20;
	cout << nearlysortary(a, n, k);

}