#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

// P.23 Ants
int main(int argc, char* argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int L, N;
  cin >> L >> N;
  vector<int> X;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    X.push_back(x);
  }
  vector<int> mins, maxes;
  for (int x : X) {
    mins.push_back(min(x, L - x));
    maxes.push_back(max(x, L - x));
  }
  cout << *max_element(mins.begin(), mins.end()) << endl;
  cout << *max_element(maxes.begin(), maxes.end()) << endl;
}
