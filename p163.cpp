#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
bool is_debug;

int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  struct S { ll value; int size; };
  using F = ll;

  int N;
  cin >> N;
  vector<S> A;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.push_back({ a, 1 });
  }

  int Q;
  cin >> Q;

  lazy_segtree<S, [](S a, S b) { return S{ a.value + b.value, a.size + b.size }; }, []() { return S{ 0, 0 }; },
               F, [](F f, S x) { return S{ x.value + x.size * f, x.size }; }, [](F f, F g) { return f + g; },
               []() { return 0; }> seg(A);
  for (int q = 0; q < Q; q++) {
    int qe;
    cin >> qe;
    if (qe == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      seg.apply(--l, r, x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << seg.prod(--l, r).value << endl;
    }
  }
}
