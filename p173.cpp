#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
bool is_debug;

vector<pair<int, int>> D[15];
// dp[i][bit], i: 現在位置, bit: 今まで通ってきたノード, value: コストの最小値
int dp[15][1 << 15];
int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int N, M;
  cin >> N >> M;
  for (int _ = 0; _ < M; _++) {
    int i, j, d;
    cin >> i >> j >> d;
    D[i].push_back({ j, d });
  }
  fill((int*) dp, (int*) (dp + 15), 1e9);
  dp[0][0] = 0;
  deque<int> que({0});
  while (!que.empty()) {
    int i = que.front();
    que.pop_front();
    for (int bit = 0; bit < (1 << N); bit++) {
      if (dp[i][bit] == 1e9) continue;
      for (auto [j, d] : D[i]) {
        if (dp[j][bit | 1 << j] < dp[i][bit] + d) {
          dp[j][bit | 1 << j] = dp[i][bit] + d;
          que.push_back(j);
        }
      }
    }
  }
  int ans = 1e9;
  for (int i = 0; i < N; i++) {
    for (auto [j, d] : D[i]) {
      if (j == 0) ans = min(ans, dp[i][(1 << N) - 2]);
    }
  }
  cout << ans << endl;
}
