#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

bool recur(vector<int>& A, int i, int K, int now) {
  bool is_matched = false;
  is_matched |= now + A[i] == K;
  if (i < A.size() - 1) {
    is_matched |= recur(A, i + 1, K, now);
    is_matched |= recur(A, i + 1, K, now + A[i]);
  }
  return is_matched;
}

// P.34 部分話問題(DFSを利用)
int main(int argc, char *argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int N;
  cin >> N;
  vector<int> A;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }
  int K;
  cin >> K;
  cout << (recur(A, 0, K, 0) ? "Yes" : "No") << endl;
}
