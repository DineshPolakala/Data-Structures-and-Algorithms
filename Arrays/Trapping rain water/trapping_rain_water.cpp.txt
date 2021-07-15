#include<bits/stdc++.h>
using namespace std;

int findWater(int *arr, int n) {
	int left_max = 0, right_max = 0;
	int res = 0;
	int low = 0, high = n - 1;
	while (low < high) {
		if (arr[low] < arr[high]) {
			if (left_max < arr[low]) {
				left_max = arr[low];
			}
			else {
				res += left_max - arr[low];
			}
			low++;
		}
		else {
			if (arr[high] > right_max) {
				right_max = arr[high];
			}
			else {
				res += right_max - arr[high];
			}
			high--;
		}
	}
	return res;
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen( "output.txt", "w", stdout);

#endif

	// write your code here
	int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Maximum water that can be accumulated is "
	     << findWater(arr, n);
	return 0;
}