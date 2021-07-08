#include <iostream>
using namespace std;

int CST(int ss, int se, int si, int arr[], int tree[])
{
	if (ss == se)
	{
		tree[si] = arr[ss];
		return arr[ss];
	}

	int mid = (ss + se) / 2;

	tree[si] = max(CST(ss, mid, 2 * si + 1, arr, tree)
	               , CST(mid + 1, se, 2 * si + 2, arr, tree));

	return tree[si];
}



int main() {
	int arr[] = {10, 20, 30, 40}, n = 4;

	int tree[4 * n];
	cout << CST(0, n - 1, 0, arr, tree) << endl;
	for (auto i : tree)
		cout << i << " ";
	cout << endl;
	PII getMinMax(PII * st, int *arr, int n, int qs, int qe)
	{
		int si = 0;
		return hmm(st, 0, n - 1, qs, qe, si);
	}
	return 0;
}