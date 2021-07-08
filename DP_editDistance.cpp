#include<bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2, int n1, int n2) {
	if (n1 == 0)return n2;
	if (n2 == 0)return n1;
	if (s1[n1 - 1] == s2[n2 - 1]) {
		return editDistance(s1, s2, n1 - 1, n2 - 1);
	}
	else {
		return 1 + min(editDistance(s1, s2, n1 - 1, n2 - 1),
		               min(editDistance(s1, s2, n1, n2 - 1 ),
		                   editDistance(s1, s2, n1 - 1, n2)));
	}
}
int editDistance_tab(string s1, string s2, int n1, int n2) {
	int dp[n1 + 1][n2 + 1];
	for (int i = 0; i <= n1; i++)
		dp[i][0] = i;
	for (int j = 0; j <= n2; j++)
		dp[0][j] = j;
	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
			}
		}
	}
	return dp[n1][n2];
}
int main() {
	string s1 = "saturday", s2 = "sunday";
	int n1 = s1.length(), n2 = s2.length();
	cout << editDistance_tab(s1, s2,  n1,  n2) << endl;

	return 0;
}