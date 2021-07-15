#include<bits/stdc++.h>
using namespace std;

double getMedian(vector<int> arr1, vector<int> arr2) {


	int n1 = arr1.size();
	int n2 = arr2.size();

	int low = 0, high = n1;
	while (low < high) {
		int cut1 = low + high  / 2;
		int cut2 = (n1 + n2 + 1) / 2 - cut1;

		int left1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1 ];
		int left2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];

		int right1 = cut1 == n1 ? INT_MAX : arr1[cut1];
		int right2 = cut2 == n2 ? INT_MAX : arr2[cut2];

		if (left1 <= right2 and left2 <= right1) {
			if (n1 + n2 / 2 == 0) {
				return ((double)max(left1, left2) + min(right1 , right2)) / 2.0;
			}
			else {
				return max(left1, left2);
			}
		}
		else if (left1 > right2) {
			high = cut1 - 1;
		}
		else
			low = cut1 + 1;
	}
	return 0.0;
}
int main() {

	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin);
	// 	freopen( "output.txt", "w", stdout);

	// #endif

	// write your code here
	vector<int > arr1{10, 20, 30, 40, 50};
	vector<int> arr2{5, 15, 25, 35, 45};
	double res = getMedian(arr1, arr2);
	cout << res;
	return 0;
}