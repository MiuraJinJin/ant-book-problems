#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

vector<pair<int, int>> path[1001];

// P.95 ベルマンフォード法
// N回全ての辺について更新確認をする(既出チェックがない)ダイクストラ
// 閉路の検出が可能
int main(int argc, char* argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u--; v--;
    path[u].push_back({ v, c });
  }

  int dist[N];
  fill((int*) dist, (int*) (dist + N), 1e9);
  dist[0] = 0;

  for (int i = 0; i < N; i++) {
    bool is_updated = false;
    for (int u = 0; u < N; u++) for (pair<int, int> p : path[u]) {
      int v = p.first, c = p.second;
      if (u != 1e9 && dist[u] + c < dist[v]) {
        dist[v] = dist[u] + c;
        is_updated = true;
      }
    }
    // N回目に更新がある場合閉路が存在している
    if (i == N - 1 && is_updated) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << dist[N - 1] << endl;
}
