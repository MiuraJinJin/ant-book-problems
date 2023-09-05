#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

// P.63 最長増加部分列問題(LIS)
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

  vector<int> lis(N + 1, 1e9);

  for (int i = 0; i < N; i++) {
    int a = A[i];
    *lower_bound(lis.begin(), lis.end(), a) = a;
  }

  if (is_debug) {
    for (int i = 0; i <= N; i++) cout << lis[i] << ' ';
    cout << endl;
  }

  int ans = 0;
  for (int i = 0; i < N; i++) if (lis[i] != 1e9) ans = i + 1;

  cout << ans << endl;
}
