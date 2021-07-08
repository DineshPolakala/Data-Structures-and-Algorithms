#include<bits/stdc++.h>
using namespace std;
int gridTraveller(int m, int n, map<string, long long int> &mp)
{
	if (mp[ to_string(n) + "," + to_string(m)])return mp[ to_string(n) + "," + to_string(m) ];
	if (m == 1 and n == 1)return 1;
	if (m == 0 or n == 0)return 0;
	mp[  to_string(n) + "," + to_string(m)] = gridTraveller(m - 1, n, mp) + gridTraveller(m, n - 1, mp);
	cout << mp[to_string(n) + "," + to_string(m)] << endl;
	return mp[  to_string(n) + "," + to_string(m)];
}
int main() {
	map<string, long long int>mp;
	cout << (gridTraveller(18, 18, mp) ) << endl;
	return 0;
}