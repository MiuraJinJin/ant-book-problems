#include <bits/stdc++.h>
#include <atcoder/all>

using namespace atcoder;
using namespace std;

// dp[i][j] i: チェックしたitemの数, j: j個選ぶ組み合わせ, value: 組み合わせの数
int dp[1001][1001];

// P.67 重複組合せ(DP)
int main(int argc, char* argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int N, M;
  cin >> N >> M;
  vector<int> A;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }
  int mod;
  cin >> mod;
  modint::set_mod(mod);

  dp[0][0] = 1;

  for (int i = 1; i <= N; i++) {
    int a = A[i - 1];
    modint cum = 0;
    for (int j = 0; j <= M; j++) {
      // i番目の数を0~a個足して新しい組み合わせを作る
      // ここは以下でもOK
      // cum = dp[i][j - 1] + dp[i - 1][j];
      cum += dp[i - 1][j];
      // aの範囲に収まらなくなる箇所を引いてあげる
      if (j - a - 1 >= 0) cum -= dp[i - 1][j - a - 1];
      dp[i][j] = cum.val();
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
