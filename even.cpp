#include<bits/stdc++.h>
using namespace std;
int getres(int n, int *arr) {
	int helper[n];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0)continue;
		else if (arr[i] > 0) {
			sum += arr[i] * (i + 1);
		}
		else
		{
			if ((sum + (arr[i] * (i + 1))) < (sum + (arr[i + 1] * (i + 1))))
				sum += (arr[i + 1] * (i + 1));
			else
				sum += arr[i] * (i + 1);
		}
	}
	return sum;

}
int main() {
	int n = 3;
	int arr[] = { -1, 3, 4};
	cout << getres(n, arr) << endl;
	int b = 3 & 3 && 4 || 6 | 6;
	cout << b << endl;



	int l, k, m;
	l = 5;
	int a[5] = {3, 4, 6, 16, 7};
	for (k = 0; k <= 4; k++) {
		if (l < a[k])
			l = a[k];
		m = l + a[k];
	}
	cout << m << endl;
	cout << (2 && 0) << endl;


	return 0;
}