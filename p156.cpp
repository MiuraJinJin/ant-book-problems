#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
bool is_debug;

int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int N, C;
  cin >> N >> C;
  vector<int> L, S, A;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    L.push_back(x);
  }
  for (int i = 0; i < C; i++) {
    int x;
    cin >> x;
    S.push_back(x);
  }
  for (int i = 0; i < C; i++) {
    int x;
    cin >> x;
    A.push_back(x - 90);
  }

  typedef tuple<double, double, double> tp;
  segtree <tp, [](tp& a, tp& b) {
    auto [xa, ya, ra] = a;
    auto [xb, yb, rb] = b;
    double si = sin(ra), cs = cos(ra);
    double x = xa + cs * xb - si * yb;
    double y = ya + si * xb + cs * yb;
    }, []() { return tp { 0.0, 0.0, M_PI / 2.0 }; }> seg(N);

  for (int i = 0; i < N; i++) {
    seg.set(i, tp { 0.0, (double) L[i], M_PI / 2.0 });
  }

  for (int c = 0; c < C; c++) {
    int s = S[c];
    double a = (double) A[c] * M_PI / 180.0;
    double l = L[c];
    seg.set(s, tp { l, l, a });
    auto [x, y, _] = seg.all_prod();
    cout << x << ' ' << y << endl;
  }
}
