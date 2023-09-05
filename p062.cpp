#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

// dp[i][j] i: 見たnumberの数, j: 作れる数, value: numberの残数
int dp[101][100001];

// P.62 個数制限付き部分和問題
int main(int argc, char* argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int N;
  cin >> N;
  vector<int> A, M;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }
  for (int i = 0; i < N; i++) {
    int m;
    cin >> m;
    M.push_back(m);
  }

  vector<pair<int, int>> numbers;
  for (int i = 0; i < N; i++) numbers.push_back({ A[i], M[i] });

  int K;
  cin >> K;

  fill((int*) dp, (int*) (dp + 101), -1);
  dp[0][0] = 0;

  for (int i = 1; i <= N; i++) {
    int a = numbers[i - 1].first, m = numbers[i - 1].second;
    for (int j = 0; j <= K; j++) {
      if (dp[i - 1][j] >= 0) dp[i][j] = m;
      if (dp[i][j - a] >= 0) dp[i][j] = dp[i][j - a] - 1;
    }
  }

  if (is_debug) {
    for (int i = 0; i <= N; i++) {
      for (int j = 0; j <= K; j++) {
        cout << dp[i][j] << ' ';
      }
      cout << endl;
    }
  }

  cout << (dp[N][K] >= 0 ? "Yes" : "No") << endl;
}
