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

  mint dp[N][M + 1][1 << M];
  fill((mint*) dp, (mint*) (dp + N), (mint) 0);
  dp[0][0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (S[i][j] == 'x') continue;
      for (int k = 0; k < (1 << M); k++) {
        // すでに塗られている場合スキップ
        if (k & 1) continue;
        // 横
        if (j + 1 < M - 1) {

        }
        // 縦
      }
    }
  }
  
}
