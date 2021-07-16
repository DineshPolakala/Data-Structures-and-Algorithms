#include<bits/stdc++.h>
using namespace std;
getSubSequence(string s1, string s2) {
	int n1 = s1.length();
	int n2 = s2.length();

	int j = 0;
	for (int i = 0; i < n1; i++) {
		if (s1[i] == s2[j]) {
			j++;
		}
	}
	return j == n2;

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen( "output.txt", "w", stdout);

#endif

	// write your code here
	string s1 = "Dinesh", s2 = "ni";
	cout << getSubSequence(s1, s2) << endl;

	return 0;
}