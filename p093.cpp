#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

vector<int> path[1001];

// P.93 二部グラフ判定
int main(int argc, char* argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    path[u].push_back(v);
    path[v].push_back(u);
  }

  map<int, int> color_map;

  bool is_ok = true;
  for (int i = 0; i < N; i++) {
    if (color_map.contains(i)) continue;
    deque<int> bfs { i };
    while (!bfs.empty()) {
      int now = bfs.front();
      bfs.pop_front();
      int now_color = color_map[now];
      for (int next : path[now]) {
        if (color_map.contains(next)) {
          if (color_map[next] == now_color) is_ok = false;
        }
        else {
          color_map[next] = now_color ^ 1;
          bfs.push_back(next);
        }
      }
    }
  }

  if (is_debug) {
    for (int i = 0; i < N; i++) cout << color_map[i] << ' ';
    cout << endl;
  }
  cout << (is_ok ? "Yes" : "No") << endl;
}
