#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
bool is_debug;

int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int Q;
  cin >> Q;

  struct S { ll value; int size; };
  using F = ll;
  lazy_segtree<S, [](S a, S b) { return S{ a.value + b.value, a.size + b.size }; }, []() { return S{ 0, 0 }; },
               F, [](F f, S x) { return S{ x.value + x.size * f, x.size }; }, [](F f, F g) { return f + g; }
               []() { return 0; }> seg(vector<S>(N, S{ 0, 1 });
  for (int q = 0; q < Q; q++) {
    int qe, l, r, x;
    cin >> qe >> l >> r >> x;
    if (qe == 1) {
      seg.apply(l, r, x);
    } else {
      cout << seg.prod(l, r).value << endl;
    }
  }
}
