#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
bool is_debug;

// dp[i][bit], i: 現在の頂点, bit: 経路, value: そこまでの最小コスト
int dp[15][1 << 15];
vector<pair<int, int>> D[15];

void recur(int i, int bit) {
  for (auto [j, d] : D[i]) {
    if (bit & (1 << j) == 1) continue;
    int next_bit = bit | (1 << j);
    if (dp[j][next_bit] > dp[i][bit] + d) {
      dp[j][next_bit] = dp[i][bit] + d;
      recur(j, next_bit);
    }
  }
}

int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int N, M;
  cin >> N >> M;
  for (int m = 0; m < M; m++) {
    int i, j, d;
    cin >> i >> j >> d;
    D[i].push_back({ j, d });
  }
  fill((int*) dp, (int*) (dp + 15), 1e9);
  dp[0][0] = 0;
  recur(0, 0);
  cout << dp[0][(1 << N) - 1] << endl;
}
