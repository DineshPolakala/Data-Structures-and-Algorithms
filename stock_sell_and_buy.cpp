#include<bits/stdc++.h>
using namespace std;
int max_profit(int *arr, int start, int end) {
    if (start >= end)return 0;
    int profit = 0;
    for (int i = start; i < end; i++) {
        for (int j = i + 1; j <= end; j++) {
            if (arr[i] < arr[j]) {
                int cur_profit = arr[j] - arr[i] + max_profit(arr, start, i - 1) +
                                 max_profit(arr, j + 1, end);
                profit = max(profit, cur_profit);
            }
        }
    }
    return profit;
}

int main() {
#ifndef ONLiNE_JUDGE
    freopen("DoublyLLinput.txt", "r", stdin);
    freopen("DoublyLLoutput.txt", "w", stdout);
#endif

    int n ;
    cin >> n;
    int arr[n] ;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << max_profit(arr, 0, n - 1);
}