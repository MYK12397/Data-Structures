#include<bits/stdc++.h>
using namespace std;
// bool searchMatrix(vector<vector<int>>& matrix, int target) {
// 	if (matrix.empty() || matrix[0].size() == 0)
// 		return false;
// 	int sr = -1;
// 	for (int i = 0; i < matrix.size(); i++)
// 	{
// 		if (matrix[i][0] > target)
// 			break;
// 		sr++;
// 	}
// 	if (sr == -1)
// 		return false;
// 	for (int i = 0; i < matrix[0].size(); i++)
// 	{
// 		if (matrix[sr][i] == target)
// 			return true;
// 	}
// 	return false;
// }
bool searchMatrix(vector<vector<int>>& a, int k) {
	int n = a.size(); int m = a[0].size();
	int l = 0, h = m - 1;
	while (l < n && h < m) {
		if (a[l][h] == k)return l, h;
		else if (a[l][h] > k)
			h--;
		else if (a[l][h] < k)
			l++;

	}
	return -1;
}
int main() {
	vector<vector<int>> mat = {{1, 4, 6, 8, 10}, {12, 14, 17, 20}, {22, 26, 28, 32}};
	int target = 17;
	cout << searchMatrix(mat, target);
	return 0;

}