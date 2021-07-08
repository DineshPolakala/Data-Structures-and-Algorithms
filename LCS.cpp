#include<bits/stdc++.h>
using namespace std;
int lcs_memo(string s1, string s2, int n1, int n2, vector<vector<int>>memo) {
	if (n1 == 0 or n2 == 0) {
		memo[n1][n2] = 0;
		return 0;
	}

	if (memo[n1][n2] != -1)return memo[n1][n2];
	else {
		if (s1[n1 - 1] == s2[n2 - 1]) {
			memo[n1][n2] = 1 + lcs_memo(s1, s2, n1 - 1, n2 - 1, memo);
		}
		else {
			memo[n1][n2] = max(lcs_memo(s1, s2, n1 - 1, n2, memo), lcs_memo(s1, s2, n1, n2 - 1, memo));
		}
	}

	return memo[n1][n2];
}

int lcs(string s1, string s2, int n1, int n2) {

}

int main()
{
	string s1 = "adcoaccob", s2 = "bodacacao";
	int n1 = 9, n2 = 9;
	vector<vector<int>>memo(n1 + 1, vector<int>(n2 + 1, -1));
	cout << lcs_memo(s1, s2, n1, n2, memo) << "\n";
	return 0;
}