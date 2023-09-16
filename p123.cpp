#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
bool is_debug;

int dp[102][102];

// P.123 Brive the Prisoners
int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int P, Q;
  cin >> P >> Q;
  vector<int> A{ 0 };
  for (int i = 0; i < Q; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }
  A.push_back(P + 1);

  // Aは囚人のいるポジションであるが両端をそれぞれA[0], A[Q+1]とする
  // dp[i][i+w]をi番目からi+w番目の囚人のいる空間(i,i+wそのものは含まない)の囚人を
  // 解放するのに必要な金貨の最低枚数とする
  // dp[i][i+1]は0となり、dp[i][i+w]=min(dp[i][k]+dp[k][i+w])+(A[i + w] - A[i] - 2)で漸化式を作れる
  // A[i + w] - A[i] - 2は今回払う必要のある金貨の枚数
  fill((int*) dp, (int*) (dp + 102), 1e9);
  for (int i = 0; i <= Q; i++) dp[i][i + 1] = 0;
  for (int w = 2; w <= Q + 1; w++) {
    for (int i = 0; i <= Q + 1 - w; i++) {
      for (int j = 1; j < w; j++) {
        int k = i + j;
        dp[i][i + w] = min(dp[i][i + w], (dp[i][k] + dp[k][i + w]) + (A[i + w] - A[i] - 2));
      }
    }
    if (is_debug) {
      for (int i = 0; i <= Q + 1; i++) {
        for (int j = 0; j <= Q + 1; j++) {
          cout << dp[i][j] << ' ';
        }
        cout << endl;
      }
      cout << endl;
    }
  }

  int ans = dp[0][Q + 1];
  cout << ans << endl;
}
