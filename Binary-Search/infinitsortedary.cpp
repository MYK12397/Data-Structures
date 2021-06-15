#include<iostream>
using namespace std;
int findPosBin(int a[], int l, int r, int x) {
	int  m;
	while (l <= r) {
		m = l + (r - l) / 2;

		if (a[m] == x && (m == 0 || a[m - 1] == 0))
			break;
		else if (a[m] == x)
		{	//res = m;
			r = m - 1;
		}
		else
			l = m + 1;
	}
	return m;
}
int main()
{
	int a[] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
	int x = 1;
	int l = 0, r = 1;
	while (a[r] == 0) {
		l = r;
		r *= 2;
	}
	cout << findPosBin(a, l, r, x);
	return 0;
}