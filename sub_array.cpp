#include<bits/stdc++.h>
using namespace std;

vector<long long> max_sum (int N, vector<int> A, int Q, vector<int> queries) {
  // Write your code here
  vector<long long>res;
  if (Q == 0 or N == 0)return res;
  sort(A.begin(), A.end());
  for (int i = 0; i < Q; i++)
  {
    int query = queries[i];
    long long sum = 0;
    for (int j = query - 1; j < N; j++)
    {

      for (int k = j; k < N; k++)
      {
        //cout<<A[k]<<" ";
        sum += A[k];
      }
    }
    //cout<<endl;
    res.push_back(sum);
  }
  return res;

}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i_A = 0; i_A < N; i_A++)
  {
    cin >> A[i_A];
  }
  int Q;
  cin >> Q;
  vector<int> queries(Q);
  for (int i_queries = 0; i_queries < Q; i_queries++)
  {
    cin >> queries[i_queries];
  }

  vector<long long> out_;
  out_ = max_sum(N, A, Q, queries);
  cout << out_[0];
  for (int i_out_ = 1; i_out_ < out_.size(); i_out_++)
  {
    cout << " " << out_[i_out_];
  }
}