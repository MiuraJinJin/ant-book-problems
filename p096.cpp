#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

vector<pair<int, int>> path[1001];
int dist[1001];

// P.96 ダイクストラ法
// 最もコストの低い順に確定させていく
int main(int argc, char* argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u--; v--;
    path[u].push_back({ c, v });
  }

  fill((int*) dist, (int*) (dist + N), 1e9);
  dist[0] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
  que.push({ 0, 0 });

  for (int i = 0; i < N; i++) {
    int u = que.top().second;
    que.pop();
    for (pair<int, int> p : path[u]) {
      int c = p.first, v = p.second;
      if (dist[u] + c < dist[v]) {
        dist[v] = dist[u] + c;
        que.push({ dist[v], v });
      }
    }
  }

  for (int i = 0; i < N; i++) cout << dist[i] << ' ';
  cout << endl;
}
