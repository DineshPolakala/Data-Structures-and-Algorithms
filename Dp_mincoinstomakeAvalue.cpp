#include<bits/stdc++.h>
using namespace std;
int getmin(int coins[] , int n, int target_sum) {
	if (target_sum == 0)return 0;
	//if(target_sum<0)return -1;
	int res = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (coins[i] <= target_sum) {

			int sub_res = getmin(coins, n, target_sum - coins[i]);
			if (sub_res != INT_MAX and sub_res + 1 < res)
				res = sub_res + 1;
		}
	}
	return res;
}

int getmin_dp(int coins[], int n, int sum) {
	int dp[sum + 1];
	dp[0] = 0;
	for (int i = 1; i <= sum; i++) {
		dp[i] = INT_MAX;
		for (int j = 0; i < n; j++) {
			if (coins[j] <= i) {
				int sub_res = dp[i - coins[j]];
				if (sub_res != INT_MAX) {
					dp[i] = min(dp[i], sub_res + 1);
				}
			}
		}
	}
	return dp[sum];
}

int main() {

	int coins[] = {25, 5, 30, 45};
	int n = sizeof(coins) / sizeof(int);
	int target_sum = 150;
	cout << "min coins is : " << getmin(coins , n , target_sum) << endl;
	return 0;
}