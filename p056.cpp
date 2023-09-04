#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

// dp[i][j] S(i + 1)までの部分文字列とT(j + 1)までの部分文字列の最長共通部分列(LCS)
// 空文字との比較の場合にindex 0を用いるため文字列のindexとずれる(1-indexedのようになる)
int dp[1001][1001];

// P.56 最長共通部分列問題(LCS)
int main(int argc, char* argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int N, M;
  cin >> N >> M;
  string S, T;
  cin >> S >> T;

  fill((int*) dp, (int*) (dp + 1001), -1e9);

  dp[0][0] = 0;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      if (i == 0 && j == 0) continue;
      int now = -1e9;
      if (i > 0) now = max(now, dp[i - 1][j]);
      if (j > 0) now = max(now, dp[i][j - 1]);
      if (i > 0 && j > 0 && S[i - 1] == T[j - 1]) now = max(now, dp[i - 1][j - 1] + 1);
      dp[i][j] = now;
    }
  }
  if (is_debug) {
    for (int i = 0; i <= N; i++) {
      for (int j = 0; j <= M; j++) {
        cout << dp[i][j] << ' ';
      }
      cout << endl;
    }
  }
  cout << dp[N][M] << endl;
}
