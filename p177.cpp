#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
bool is_debug;

int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int N, M, mod;
  cin >> N >> M >> mod;
  using mint = dynamic_modint<0>;
  mint::set_mod(mod);

  char S[N][M];
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < M; j++) S[i][j] = s[j];
  }

  mint dp[N + 1][M][1 << M];
  fill((mint*) dp, (mint*) (dp + N), (mint) 0);
  dp[0][0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (S[i][j] == 'x') continue;
      for (int bit = 0; bit < (1 << M); bit++) {
        // すでに塗られている場合スキップ
        if (bit & 1) {
          if (j < M - 1) {
            dp[i][j + 1][bit >> 1] += dp[i][j][bit];
          } else {
            dp[i + 1][0][bit >> 1] += dp[i][j][bit];
          }
          continue;
        }
        // 横
        if (j + 1 < M - 1 && (bit >> 1 & 1) == 0) {
          dp[i][j + 1][bit >> 1 | 1] += dp[i][j][bit];
        }
        // 縦
        if (j + 1 < N - 1) {
          if (j < M - 1) {
            dp[i][j + 1][bit >> 1 | 1 << M] += dp[i][j][bit];
          } else {
            dp[i + 1][0][bit >> 1 | 1 << M] += dp[i][j][bit];
          }
        }
      }
      if (is_debug) {
        cout << i << ',' << j << endl;
        for (int bit = 0; bit < 1 << M; bit++) {
          // if (dp[i][j][bit] != mint(0))
            cout << bit << ':' << dp[i][j][bit].val() << ' ';
        }
        cout << endl;
      }
    }
  }
  cout << dp[N + 1][0][0].val() << endl;
}
