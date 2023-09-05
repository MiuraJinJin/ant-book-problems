#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

// dp[i][j] i: itemsを見た数, j: 価値, value: i,jで達成可能な最小の重さ
int dp[101][10001];
int main(int argc, char *argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int N;
  cin >> N;
  vector<pair<int, int>> items;
  for (int i = 0; i < N; i++) {
    int w, v;
    cin >> w >> v;
    items.push_back({w, v});
  }
  int W;
  cin >> W;

  int total_value = 0;
  for (pair<int, int> item : items) total_value += item.second;

  fill((int*) dp, (int*) (dp + 101), 1e9);
  dp[0][0] = 0;

  for (int i = 1; i <= N; i++) {
    int w = items[i - 1].first, v = items[i - 1].second;
    for (int j = 0; j < total_value; j++) {
      int now = dp[i - 1][j];
      if (j - v >= 0) {
        now = min(now, dp[i - 1][j - v] + w);
      }
      dp[i][j] = now;
    }
  }

  if (is_debug) {
    for (int i = 0; i <= N; i++) {
      for (int j = 0; j < total_value; j++) {
        cout << dp[i][j] << ' ';
      }
      cout << endl;
    }
  }

  int ans = 0;
  for (int i = 0; i <= total_value; i++) if (dp[N][i] <= W) ans = i;

  cout << ans << endl;
}
