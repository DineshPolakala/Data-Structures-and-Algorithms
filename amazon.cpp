#include<bits/stdc++.h>
using namespace std;
int mergeFiles(vector<int> fileSizes) {
	priority_queue<int, vector<int>, greater<int>>pq;
	int res = 0;
	for (int i = 0; i < fileSizes.size(); i++) {
		pq.push(fileSizes[i]);
	}
	cout << pq.size() << endl;
	// for (int i = 0; i < 4; i++) {
	// 	cout << pq.top() << " ";
	// 	pq.pop();
	// }


	cout << endl;
	int ans = 0;
	int i = 0;
	while (i < 3) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		res = a + b;
		ans += res;
		//cout << ;
		cout << "" << " " << ans << " ";
		pq.push(res);
		i++;

	}
	return ans;

}

int main() {
	vector<int>arr{4, 8, 6, 12};
	cout << mergeFiles(arr) << endl;

	return 0;
}