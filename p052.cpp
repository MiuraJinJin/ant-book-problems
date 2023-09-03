#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int dp[101][10001];

// P.52 01ナップサック問題
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

  fill((int*) dp, (int*) dp + 101, -1e9);
  dp[0][0] = 0;

  for (int i = 0; i < N; i++) {
    int w = items[i].first, v = items[i].second;
    for (int j = 0; j <= W; j++) {
      dp[i + 1][j] = dp[i][j];
      if (j - w >= 0)
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - w] + v);
    }
  }
  cout << *max_element(begin(dp[N]), end(dp[N])) << endl;
}
