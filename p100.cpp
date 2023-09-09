#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

// P.101 最小全域木(MST, Minimum Spanning Tree, 辺の和が最小となり全てのノードに行き来可能な連結成分)
// クラスカル法(コストの低い順に辺を繋げていき既出の場合無視する)
int main(int argc, char* argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int N, M;
  cin >> N >> M;

  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> path;
  for (int i = 0; i < M; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    path.push({ c, --u , --v });
  }

  dsu uf(N);

  int ans = 0;

  while (!path.empty()) {
    tuple<int, int, int> tpl = path.top();
    path.pop();
    auto [c, u, v] = tpl;
    if (uf.same(u, v)) continue;
    uf.merge(u, v);
    ans += c;
  }

  cout << ans << endl;
}
