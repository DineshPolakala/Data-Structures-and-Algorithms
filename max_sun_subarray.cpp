#include<bits/stdc++.h>
using namespace std;

int max_subArray_sum(int *arr, int n) {
	int cur_max = arr[0];
	int max_sum = arr[0];
	for (int i = 1; i < n; i++) {
		cur_max = max(arr[i], cur_max + arr[i]);
		max_sum = max(max_sum, cur_max);
	}
	return max_sum;
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen( "output.txt", "w", stdout);

#endif

	// write your code here
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << max_subArray_sum(arr, n) << endl;
	return 0;
}