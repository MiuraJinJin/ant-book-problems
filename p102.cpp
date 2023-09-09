#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

vector<pair<int, int>> path[5001];

int main(int argc, char* argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int N, M;
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    path[--u].push_back({ --v, c });
    path[v].push_back({ u, c });
  }

  int dist[N][2];
  fill((int*) dist, (int*) (dist + N), 1e9);
  dist[0][0] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
  que.push({ 0, 0 });

  while (!que.empty()) {
    int u = que.top().second, c = que.top().first;
    que.pop();
    if (dist[u][1] < c) continue;
    for (pair<int, int> p : path[u]) {
      int v = p.first, c2 = c + p.second;
      if (c2 < dist[v][0]) {
        dist[v][1] = dist[v][0];
        dist[v][0] = c2;
        que.push({ c2, v });
      }
      else if (c2 < dist[v][1]) {
        dist[v][1] = c2;
        que.push({ c2, v });
      }
    }
  }

  if (is_debug) {
    for (int i = 0; i < N; i++) cout << dist[i][0] << ' ';
    cout << endl;
    for (int i = 0; i < N; i++) cout << dist[i][1] << ' ';
    cout << endl;
  }

  cout << dist[N - 1][1] << endl;
}
