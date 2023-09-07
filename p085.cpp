#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

// P.85 食物連鎖
int main(int argc, char* argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int N, K;
  cin >> N >> K;

  // 0~N-1: A, N~2*N-1: B, 2*N~3*N-1: C
  // 3つあるけどxがAの時で矛盾判定は行う
  dsu uf(3 * N);
  int ans = 0;

  for (int k = 0; k < K; k++) {
    int t, x, y;
    cin >> t >> x >> y;
    x--; y--;

    if (x < 0 || N <= x || y < 0 || N <= y) {
      ans++;
      continue;
    }
    if (t == 1) {
      if (uf.same(x, N + y) || uf.same(x, 2 * N + y)) {
        ans++;
        continue;
      }
      uf.merge(x, y);
      uf.merge(N + x, N + y);
      uf.merge(2 * N + x, 2 * N + y);
    }
    else {
      if (uf.same(x, y) || uf.same(x, 2 * N + y)) {
        ans++;
        continue;
      }
      uf.merge(x, N + y);
      uf.merge(N + x, 2 * N + y);
      uf.merge(2 * N + x, y);
    }
  }

  cout << ans << endl;
}
