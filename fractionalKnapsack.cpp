#include<bits/stdc++.h>
using namespace std;
bool mycmp(pair<int, int>a, pair<int, int>b)
{
	double r1 = (double)a.second / a.first;
	double r2 = (double)b.second / b.first;
	return r1 > r2;
}
int fractionalknapsack(vector<pair<int, int>>&arr, int knapsack)
{
	int res = 0;
	int n = arr.size();
	// sorting in a decreasing order of value per weight
	sort(arr.begin(), arr.end(), mycmp);
	for (int i = 0; i < n; i++)
	{
		if (arr[i].first <= knapsack )
		{
			res += ( arr[i].second);
			knapsack -= arr[i].first;
		}
		else
		{
			res += knapsack * (arr[i].second / arr[i].first);
			break;
		}
	}
	return res;
}
int main()
{
	//pai<int,int> ---->  pair<weight,value>
	vector<pair<int, int>>arr{{30, 120}, {20, 100}, {10, 60}};
	int knapsack;
	cout << fractionalknapsack(arr, knapsack = 50) << endl;
	return 0;
}