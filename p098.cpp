#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

vector<pair<int, int>> path[1001];
int dist[1001];
// 1つ前のノードを格納
int pre_nodes[1001];

// P.98 経路復元
int main(int argc, char* argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int N, M;
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u--; v--;
    path[u].push_back({ c, v });
    path[v].push_back({ c, u });
  }

  fill((int*) dist, (int*) (dist + 1001), 1e9);
  dist[0] = 0;
  fill((int*) pre_nodes, (int*) (pre_nodes + 1001), -1);

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
  que.push({ 0, 0 });

  while (!que.empty()) {
    int u = que.top().second;
    que.pop();
    for (pair<int, int> p : path[u]) {
      int v = p.second, c = p.first;
      if (dist[v] > c + dist[u]) {
        dist[v] = dist[u] + c;
        que.push({ dist[v], v });
        pre_nodes[v] = u;
      }
    }
  }

  for (int i = 0; i < N; i++) cout << dist[i] << ' ';
  cout << endl;
  int i = N - 1;
  do {
    cout << i << ' ';
    i = pre_nodes[i];
  } while(i != -1);
  cout << endl;
}
