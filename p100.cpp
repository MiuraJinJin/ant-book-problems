#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int dist[1001];
vector<pair<int, int>> path[1001];

// P.100 最小全域木(MST, Minimum Spanning Tree, 辺の和が最小となり全てのノードに行き来可能な連結成分)
// プリム法(ダイクストラの要領で採用する辺を決めていく)
int main(int argc, char* argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int N, M;
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u--; v--;
    path[u].push_back({ v, c });
    path[v].push_back({ u, c });
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
  que.push({ 0, 0 });

  fill((int*) dist, (int*) (dist + 1001), 1e9);
  dist[0] = 0;

  set<int> checked;

  int ans = 0;

  while (!que.empty()) {
    int u = que.top().second, c = que.top().first;
    que.pop();
    if (checked.contains(u)) continue;
    checked.insert(u);
    ans += c;

    for (pair<int, int> p : path[u]) {
      int v = p.first, c = p.second;
      if (dist[v] > dist[u] + c) {
        dist[v] = dist[u] + c;
        que.push({ c, v });
      }
    }
  }

  if (is_debug) for (int i = 0; i < N; i++) cout << dist[i] << ' ';
  cout << endl;

  cout << ans << endl;
}
