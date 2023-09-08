#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

// dp[k][i][j] k: k個のノードを見る, i: 始点, j: 終点, value: 最短距離
int dp[101][101][101];

// P.98 ワーシャルフロイド法
int main(int argc, char* argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  fill((int*) dp, (int*) (dp + 101), 1e9);

  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++) dp[0][i][i] = 0;
  for (int i = 0; i < M; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u--; v--;
    dp[0][u][v] = min(dp[0][u][v], c);
    dp[0][v][u] = min(dp[0][v][u], c);
  }

  for (int k = 1; k <= N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
    dp[k][i][j] = min(dp[k - 1][i][j], dp[k - 1][i][k - 1] + dp[k - 1][k - 1][j]);
  }

  for (int k = 0; k <= N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cout << dp[k][i][j] << ' ';
      }
      cout << endl;
    }
    cout << endl << endl;
  }
  cout << dp[N][0][N - 1] << endl;
}
