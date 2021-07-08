#include<bits/stdc++.h>
using namespace std;

void reverse(int *arr, int n) {
    int l = 0;
    int r = n - 1;
    while (l < r) {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }

}
void rotate(int arr[][4], int &n) {
    //int n= sizeof(arr)/sizeof(int);
    // transpose
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
    // reverse
    for (int i = 0; i < n; i++) {
        reverse(arr[i], n);
    }

}

int main() {
    int arr[4][4] = {{1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int n = sizeof(arr) / sizeof(arr[0]);
    rotate(arr, n);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; i < 4; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}