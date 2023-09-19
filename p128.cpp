#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
bool is_debug;

// 二分探索は最終的にokとngの境界までわかる
int lower_bound(vector<int> A, int X) {

  int ng = -1, ok = A.size();
  while (ok - ng > 1) {
    int mid = (ok + ng) / 2;
    if (A[mid] >= X) ok = mid;
    else ng = mid;
  }
  return ok;
}

// P.128 lower_bound
int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int N;
  cin >> N;
  vector<int> A;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }
  A.push_back(2e9);
  int K;
  cin >> K;

  cout << lower_bound(A, K) << endl;
}
