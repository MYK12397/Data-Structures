#include <bits/stdc++.h>
#define ll long long int
#define se second
#define fi first
#define pb push_back
#define rep(i,a,n) for(int i=a;i<n;i++)
using namespace std;
int num_painter(int a[], int n, int maxlen) {
  int cnt = 1, s = 0;//here cnt is 1 because one painter can paint alone.

  rep(i, 0, n)
  {
    s += a[i];
    if (s > maxlen) {//maxlen: maximum time for 1 painter to paint boards
      s = a[i];
      cnt++;
    }
  }
  return cnt;
}
int main() {
  int ar[] = {10, 20, 30, 40}, s = 0;
  int n = sizeof(ar) / sizeof(ar[0]);
  int l = *max_element(ar, ar + n);
  rep(i, 0, n)s += ar[i];
  int r = s;
  int ans, k = 2;

  while (l <= r) {
    int m = l + (r - l) / 2;
    int painters_Required = num_painter(ar, n, m);
    if (painters_Required > k)
      l = m + 1;
    else {
      ans = m;
      r = m - 1;
    }
  }
  cout << ans << '\n';

  return 0;
}