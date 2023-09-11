#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

vector<pair<int, int>> path[1001];
int dist[1001];

// P.104 Layout
// 不等式をグラフに落とし込む問題
// dist[u], dist[v], edge(u -> v): wがある時にdist[v] <= dist[u] + w
// が成り立つことを利用する
int main(int argc, char* argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int N, AL, AD;
  cin >> N >> AL >> AD;
  for (int i = 1; i < N; i++) path[i].push_back({ i - 1, 0 });

  for (int i = 0; i < AL; i++) {
    int al, bl, dl;
    cin >> al >> bl >> dl;
    al--; bl--;
    path[al].push_back({ bl, dl });
  }

  for (int i = 0; i < AD; i++) {
    int ad, bd, dd;
    cin >> ad >> bd >> dd;
    ad--; bd--;
    path[bd].push_back({ ad, -dd });
  }

  // ベルマンフォード
  fill((int*) dist, (int*) dist + 1001, 1e9);
  dist[0] = 0;
  for (int i = 0; i < N; i++) {
    bool updated = false;
    for (int a = 0; a < N; a++) for (auto [b, d] : path[a]) {
      if (dist[a] != 1e9 && dist[b] > dist[a] + d) {
        dist[b] = dist[a] + d;
        updated = true;
      }
    }
    // 閉路ありの場合
    if (!updated) break;
    if (i == N - 1) {
      cout << -1 << endl;
      return 0;
    }
  }

  if (is_debug) {
    for (int i = 0; i < N; i++) cout << dist[i] << ' ';
    cout << endl;
  }

  if (dist[N - 1] == 1e9) {
    cout << -2 << endl;
    return 0;
  }

  cout << dist[N - 1] << endl;
}
