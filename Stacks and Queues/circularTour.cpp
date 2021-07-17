#include<bits/stdc++.h>
using namespace std;

struct cell {
    int petrol, dist;
    cell(int petrol, int dist) {
        this->petrol = petrol;
        this->dist = dist;
    }
};

int circularTour(vector<cell> arr) {
    if (arr.size() == 0)return 0;
    int balancePetrol = 0, prevPetrol = 0;
    int start = 0;
    for (int i = 0; i < arr.size() ; i++) {
        balancePetrol += arr[i].petrol - arr[i].dist;
        if (balancePetrol < 0) {
            prevPetrol += balancePetrol;
            balancePetrol = 0;
            start = i + 1;
        }
    }
    return (balancePetrol + prevPetrol >= 0) ? start + 1 : -1;
}

int main() {

    vector< cell> arr{{6, 4}, {3, 6}, {7, 3}};

    int position = circularTour(arr);
    cout << position << endl;


}
