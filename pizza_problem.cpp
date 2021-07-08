#include<bits/stdc++.h>
using namespace std;
struct data {
	int time;
	int num_pizzas;
	string place;
	data(int time, int num_pizzas, string place) {
		this->time = time;
		this->num_pizzas = num_pizzas;
		this-> place = place;

	}
};
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen( "output.txt", "w", stdout);

#endif

	// write your code here

	// start time = 6:00
	string places[] = {"Ameerpet", "Panjagutta", "Begumpet", "Khairatabad"};
	unordered_map<int, string> mp;

	queue<data>q;
	int i = 2, k = 0;
	while (i <= 30 ) {
		q.push(data(i, i % 3 + 1, places[k % 4] ));
		mp[i] = places[k % 4];

		k++;
		k = k % 4;

		i += 2;
	}

	int delivery_boy_pickup_time[] = {0, 0, 0, 0};
	while (q.empty() == false) {
		data cur = q.front();
		q.pop();
		cout << cur.time << " " << cur.num_pizzas << " " << cur.place << endl;
	}

	// int time = 2 ;
	// int num_pizzas;


	// while (true) {

	// 	if (time % 2 == 0) {
	// 		// take call

	// 	}


	// 	time++;

	// }






	return 0;
}