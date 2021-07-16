#include<bits/stdc++.h>
using namespace std;
int getLeftEff1(string s) {
	unordered_map<char, int> mp;
	int res = INT_MAX;
	for (int i = 0; i < s.length(); i++) {
		if (mp.find(s[i]) == mp.end()) {
			mp[s[i]] = i;
			// cout << mp[s[i]] << " ";
		}

		else {
			res = min(res, mp[s[i]]);
		}

	}
	return res;

}

int getLeftEff2(string s) {
	int n = s.length();
	vector<bool> visited(256, false);
	int res = -1;

	for (int i = n - 1; i >= 0; i--) {
		if (visited[s[i]])
			res = i;
		else
			visited[s[i]] = true;
	}
	return res;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen( "output.txt", "w", stdout);

#endif

	// write your code here
	string s = "abccbd";
	cout << getLeftEff2(s);
	return 0;
}