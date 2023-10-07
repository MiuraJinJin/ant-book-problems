#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
bool is_debug;

vector<pair<int, double>> path[8];
double dist[30][1 << 10];
int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int N, M, L;
  cin >> N >> M >> L;
  for (int i = 0; i < L; i++) {
    int u, v;
    double d;
    cin >> u >> v >> d;
    --u; --v;
    path[u].push_back({ v, d });
    path[v].push_back({ u, d });
  }
  int A, B;
  cin >> A >> B;
  --A; --B;
  vector<double> T;
  for (int i = 0; i < N; i++) {
    double t;
    cin >> t;
    T.push_back(t);
  }
  fill((double*) dist, (double*) (dist + 30), (double) 1e9);
  dist[A][0] = 0.0;
  deque<pair<int, int>> dfs;
  dfs.push_back({ A, 0 });
  while (!dfs.empty()) {
    auto [now, bit] = dfs.back();
    dfs.pop_back();
    for (int i = 0; i < N + 1; i++) {
      double t = 1.0;
      if (i < N && ((bit >> i) & 1) == 0) t = T[i];
      int next_bit = bit | 1 << i;
      if (i == N) next_bit = bit;
      for (auto [nxt, d] : path[now]) {
        if (dist[nxt][next_bit] > dist[now][bit] + d / t) {
          dist[nxt][next_bit] = dist[now][bit] + d / t;
          dfs.push_back({ nxt, next_bit });
        }
      }
    }
  }

  if (is_debug) {
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < (1 << N); j++) {
        cout << dist[i][j] << ' ';
      }
      cout << endl;
    }
  }

  double ans = (double) 1e9;
  for (int i = 0; i < (1 << N); i++) {
    ans = min(ans, dist[B][i]);
  }

  if (ans == (double) 1e9) {
    cout << "inpossible" << endl;
  }
  else {
    cout << ans << endl;
  }
}
