#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

// P.021 三角形
int main(int argc, char* argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int N;
  cin >> N;
  vector<int> A;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }
  int ans = 0;
  for (int i = 0; i < N - 2; i++) for (int j = i + 1; j < N - 1; j++) for (int k = j + 1; k < N; k++) {
    if (A[i] < A[j] + A[k] && A[j] < A[i] + A[k] && A[k] < A[i] + A[j]) ans = max(ans, A[i] + A[j] + A[k]);
  }
  cout << ans << endl;
}
