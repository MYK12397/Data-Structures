#include<iostream>
using namespace std;
char bs(char a[], int n, char k) {
	char res = '#';
	int l = 0, r = n - 1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (a[m] == k)
			l = m + 1;
		else if (a[m] < k)
			l = m + 1;
		else {
			res = a[m];
			r = m - 1;
		}
	}
	return res;
}

int main()
{
	char a[] = {'a', 'b', 'c', 'f', 'h'};
	int n = sizeof(a) / sizeof(a[0]);
	char k = 'a';
	cout << bs(a, n, k);
	return 0;
}