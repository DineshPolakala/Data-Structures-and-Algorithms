#include<bits/stdc++.h>
using namespace std;
int trapping_water(int *arr, int n) {
	int left_max[n];
	int right_max[n];
	left_max[0] = arr[0];
	for (int i = 1; i < n; i++) {
		left_max[i] = max(left_max[i - 1], arr[i]);
	}
	right_max[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		right_max[i] = max(right_max[i + 1], arr[i]);
	}
	int res = 0;

	for (int i = 1; i < n; i++) {
		res += min(left_max[i], right_max[i]) - arr[i];
	}
	return res;
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen( "output.txt", "w", stdout);

#endif
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << trapping_water(arr, n);
	return 0;
}