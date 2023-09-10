#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

vector<pair<int, int>> path[10001];

// P.103 Conscription(クラスカル法を利用)
// 一旦連結成分に分けて問題を考えたがそれをせずにもクラスカル法のみでsolve可能である
// (クラスカル法は全域木の集合体である森の全ての辺のコストを計算可能である)
int main(int argc, char* argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int N, M, R;
  cin >> N >> M >> R;

  dsu uf(N + M);

  for (int r = 0; r < R; r++) {
    int x, y, d;
    cin >> x >> y >> d;
    uf.merge(x, y + N);
    path[x].push_back({ y + N, d });
    path[y + N].push_back({ x, d });
  }

  int ans = 0;
  dsu uf2(N + M);
  for (vector<int> g : uf.groups()) {
    ans += 10000;
    vector<tuple<int, int, int>> vec;
    for (int member : g) {
      for (pair<int, int> p : path[member]) {
        vec.push_back({ member, p.first, p.second });
      }
    }
    sort(vec.begin(), vec.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
      return get<2>(a) > get<2>(b);
    });
    for (tuple<int, int, int> tpl : vec) {
      auto [a, b, d] = tpl;
      if (uf2.same(a, b)) continue;
      ans += 10000 - d;
      uf2.merge(a, b);
    }
  }
  cout << ans << endl;
}
