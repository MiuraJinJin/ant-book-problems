#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
bool is_debug;

// P.119 Crazy Rows(バブルソートっぽいやつ)
int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int N;
  cin >> N;
  vector<vector<int>> tbl;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    tbl.push_back(vector<int>());
    for (char c : s) tbl.back().push_back(c - '0');
  }

  int ans = 0;
  for (int i = 0; i < N - 1; i++) {
    int swap_index = -1;
    for (int j = i; j < N && swap_index == -1; j++) {
      for (int k = N - 1; k >= 0; k--) {
        if (tbl[j][k] == 1) {
          if (k <= i) swap_index = j;
          break;
        }
      }
    }
    if (is_debug) cout << swap_index << endl;
    ans += swap_index - i;
    for (int j = swap_index; j > i; j--) {
      swap(tbl[j], tbl[j - 1]);
    }
  }
  cout << ans << endl;
}
