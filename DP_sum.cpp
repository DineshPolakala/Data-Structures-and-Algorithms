#include<bits/stdc++.h>
using namespace std;
int getcount(int targetsum, int* coins, int n) {
	if (targetsum == 0)return 1;
	if (targetsum < 0)return 0;
	if (n == 0)return 0;
	//int res = 0;
	int res = getcount(targetsum, coins, n - 1);
	res += getcount(targetsum - coins[n - 1], coins, n);
	return res;
}
// by making tabulation matrix as sum X coins
int getcount_tab(int targetsum, int*coins, int n) {
	int tab[targetsum + 1][n + 1];

	for (int i = 0; i <= n; i++)
		tab[0][i] = 1;
	for (int i = 0; i <= targetsum; i++)
		tab[i][0] = 0;
	for (int i = 1; i <= targetsum; i++) {
		for (int j = 1; j <= n; j++) {
			tab[i][j] = tab[i][j - 1];
			if ( coins[j - 1] <= i) {
				tab[i][j] += tab[i - coins[j - 1]][j];
			}
		}
	}
	return tab[targetsum][n];
}

// by making tabulation matrix as coins X sum
int getcount_tab_cXs(int targetsum, int*coins, int n) {
	int tab[n + 1][targetsum + 1];
	for (int i = 0; i < n; i++) {
		tab[i][0] = 1;
	}
	for (int i = 1; i <= targetsum; i++) {
		tab[0][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= targetsum; j++) {
			tab[i][j] = tab[i - 1][j];
			if (j - coins[i - 1] >= 0) {
				tab[i][j] += tab[i][j - coins[i - 1]];
			}
		}
	}
	return tab[n][targetsum];
}
int main() {
	int coins[] = {9, 6, 2, 11, 1, 10};
	int  n = sizeof(coins) / sizeof(int);
	int sum = 11;
	cout << getcount_tab(sum, coins, n) << endl;
	cout << getcount_tab_cXs(sum, coins, n) << endl;
	return 0;
}