#include<bits/stdc++.h>
using namespace std;
void print_subsets(string s, string cur , int i) {
	if (i == s.length())
	{
		cout << cur << endl;
		return ;
	}
	print_subsets(s, cur, i + 1);
	print_subsets(s, cur + s[i], i + 1);
}


int main() {

	string s = "abc";
	string cur;
	int index;
	print_subsets(s, cur = "", index = 0);
	return 0;
}