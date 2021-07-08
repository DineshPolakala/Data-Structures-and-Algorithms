#include<bits/stdc++.h>
using namespace std;
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen( "output.txt", "w", stdout);

#endif

	// write your code here

	int num_plants;
	cout << "enter the number of plants" << endl;
	cin >> num_plants;

	int bucket_cap;
	cout << "enter the capacity of the bucket" << endl;
	cin >> bucket_cap;

	int mug_cap;
	cout << "enter the capacity of the mug" << endl;
	cin >> mug_cap;

	double tap_speed;
	cout << "Enter the relative speed of the tap (Lit/sec)" << endl;
	cin >> tap_speed;

	double time_taken_to_fill_bucket = bucket_cap / tap_speed;
	double time_taken_to_fill_mug = mug_cap / tap_speed;

	int mugs_req_for_plant;
	cout << "enter the number of mugs required to fill each plant" << endl;
	cin >> mugs_req_for_plant;

	int time_frwd;
	cout << "Enter the time required to reach the plant" << endl;
	cin >> time_frwd;

	int pour_sec;
	cout << "How mant seconds will it take to pour each plant" << endl;
	cin >> pour_sec;

	int time = time_taken_to_fill_mug;
	int bucket_fill_plants = bucket_cap / (mug_cap * mugs_req_for_plant);

	if (bucket_fill_plants >= num_plants) {
		time = time_frwd + time_taken_to_fill_bucket + (num_plants * pour_sec);
		return 0;
	}

	int filled_plants = 0;
	double bucket_filled = 0;
	int next_plant_fill_time, next_mug_fill_time;
	int num_times_plant_filled = 0;
	int cur_mug = 1;

	next_plant_fill_time = time + time_frwd;
	next_mug_fill_time = time + (time_frwd * 2);
	while (filled_plants < num_plants) {
		if (time == next_mug_fill_time and bucket_fill_plants >= num_plants - filled_plants) {
			time += time_frwd + ((bucket_cap - bucket_filled) / tap_speed) + (num_plants - filled_plants) * pour_sec;
			break;
		}

		if (time == next_plant_fill_time) {
			num_times_plant_filled++;
			if (num_times_plant_filled == mugs_req_for_plant ) {
				filled_plants++;
				num_times_plant_filled = 0;
			}
		}
		if (time == next_mug_fill_time) {
			cur_mug++;
			bucket_filled -= mug_cap;
			next_plant_fill_time = time + time_frwd;
			next_mug_fill_time = time + (time_frwd * 2);

		}
		time++;
		bucket_filled += tap_speed;
	}

	cout << "Time required to fill the plants is " << time << " sec" << endl;
	return 0;
}
