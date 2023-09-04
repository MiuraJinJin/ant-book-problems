#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

// dp[i][j] items[i - 1]まで見た時のWで最も高い価値
int dp[101][10001];

// P.58 個数制限なしナップサック問題
int main(int argc, char* argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int N;
  cin >> N;
  vector<pair<int, int>> items;
  for (int i = 0; i < N; i++) {
    int w, v;
    cin >> w >> v;
    items.push_back({ w, v });
  }
  int W;
  cin >> W;

  fill((int*) dp, (int*) (dp + 101), -1e9);

  dp[0][0] = 0;

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= W; j++) {
      int w = items[i - 1].first, v = items[i - 1].second;
      int now = dp[i - 1][j];
      if (j >= w) {
        if (dp[i - 1][j - w] != -1e9) now = max(now, dp[i - 1][j - w] + v);
        if (dp[i][j - w] != -1e9) now = max(now, dp[i][j - w] + v);
      }
      dp[i][j] = now;
    }
  }

  if (is_debug) {
    for (int i = 0; i <= N; i++) {
      for (int j = 0; j < W; j++) {
        cout << dp[i][j] << ' ';
      }
      cout << endl;
    }
  }

  cout << *max_element(begin(dp[N]), end(dp[N])) << endl;
}
