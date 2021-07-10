#include<bits/stdc++.h>
using namespace std;
// given an array of integers. find the length of the largest increasing sub sequence.
// Eg: {3,4,7,2,1,11,10,14}
// ans = 5 ie. {3,4,7,11,14} or {3,4,7,10,14} so max length is 5


int findCeil(int *arr, int start, int end, int key) {
    while (start < end) {
        int mid = start + (end - start) / 2;
        //if(arr[mid] == key)return mid;
        if (arr[mid] >= key)
            end = mid;
        else {
            start = mid + 1;
        }
    }
    return end;
}

int lisnlogn(int arr[], int n) {
    int lis[n];
    int len = 1;
    lis[0] = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > lis[len - 1]) {
            lis[len] = arr[i];
            len++;
        }
        else {
            int index = findCeil(lis, 0, len - 1, arr[i] );
            lis[index] = arr[i];
        }


    }
    return len;
}

int main() {
    int arr[] = {3, 4, 7, 2, 1, 11, 10, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << lisnlogn(arr, size) << endl;
}