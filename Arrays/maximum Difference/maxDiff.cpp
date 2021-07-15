#include<bits/stdc++.h>
using namespace std;

int maxDiff(int *arr, int n) {
	int min_val = arr[0];
	int res = arr[1] - arr[0];
	for (int i = 1; i < n; i++) {
		res = max(res, arr[i] - min_val);
		min_val = min(arr[i], min_val);
	}
	return res;
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen( "output.txt", "w", stdout);

#endif

	// write your code here
	int arr[] = {2, 3, 10, 6, 4, 8, 1}, n = 7;

	cout << maxDiff(arr, n);


	return 0;
}