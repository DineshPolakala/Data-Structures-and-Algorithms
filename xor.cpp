#include<bits/stdc++.h>
using namespace std;

long long pair_sum (int N, vector<int> arr) {
  // Write your code here
  /*long long sum =0;
  for(int i=0; i< N-1;i++)
  {
      for(int j= i+1; j < N; j++)
      {
          long long x = (arr[i] ^ (arr[i] + arr[j])) +
                       (arr[j] ^ (arr[i] + arr[j]));
          sum +=x;
      }
  }
  return sum;*/

  long long sum = 0;
  for (int i = 0; i < 32; i++)
  {
    int zc = 0, oc = 0;
    long long int idsum = 0;
    for (int i = 0; i < N; i++)
    {

    }
  }

}

int main() {

#ifndef ONLINE_JUDGE
  freopen("MERGELLinput.txt", "r", stdin);
  freopen("MERGELLoutput.txt", "w", stdout);
#endif
  int T;
  cin >> T;
  for (int t_i = 0; t_i < T; t_i++)
  {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i_arr = 0; i_arr < N; i_arr++)
    {
      cin >> arr[i_arr];
    }

    long long out_;
    out_ = pair_sum(N, arr);
    cout << out_;
    cout << "\n";
  }
}