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
    A.push_back(x);
  }

  vector<double> rads(N - 1, M_PI);
  double now = accumulate(L.begin(), L.end(), 0);

  typedef tuple<double, double, double> tp;
  segtree <tp, [](tp& a, tp& b) {
    auto [xa, ya, ra] = a;
    auto [xb, yb, rb] = b;
    double si = sin(ra), cs = cos(ra);
    double x = xa + cs * xb - si * yb;
    double y = ya + si * xb + cs * yb;
    }, []() { return 1e18; }> seg(N);

  for (int c = 0; c < C; c++) {
    
  }
}
