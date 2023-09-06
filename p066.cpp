#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

// dp[i][j] jのi分割の総数(合計するとjになる、0以上の和の項がi個ある場合の数)
// 2つのスライドがある (i, j) = (3, 4)
// 1. dp[i][j] = dp[i - 1][j] (新しく生えるパターン)
//   { 0 + 4, 1 + 3, 2 + 2 } -> { 0 + 0 + 4, 0 + 1 + 3, 0 + 2 + 2 }
// 2. dp[i][j] = dp[i][j - i] (底上げされるパターン)
//   { 0 + 0 + 1 } -> { (0 + 1) + (0 + 1) + (1 + 1) }
int dp[1001][1001];

// P.66 分割数
int main(int argc, char* argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int N, M, mod;
  cin >> N >> M >> mod;

  // 0の0分割は存在しないパターンが1つのみあると考える
  dp[0][0] = 1;
  for (int i = 1; i <= M; i++) for (int j = 0; j <= N; j++) {
    dp[i][j] = dp[i - 1][j];
    if (j - i >= 0) {
      dp[i][j] += dp[i][j - i];
      dp[i][j] %= mod;
    }
  }

  if (is_debug) {
    for (int i = 0; i <= M; i++) {
      for (int j = 0; j <= N; j++) {
        cout << dp[i][j] << ' ';
      }
      cout << endl;
    }
  }

  cout << dp[M][N] << endl;
}
