#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
bool is_debug;

using mint = static_modint<10000>;
typedef vector<vector<mint>> vvm;

vvm mlt(vvm& a, vvm& b) {
  vvm c = { { 0, 0 }, { 0, 0 } };
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return c;
}

int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  ll N;
  cin >> N;
  vvm a = { { 1, 1 },
            { 1, 0 } };
  vvm b = { { 1, 0 },
            { 0, 1 } };
  while (N > 0) {
    if (N & 1) b = mlt(a, b);
    a = mlt(a, a);
    N >>= 1;
  }
  cout << b[1][0].val() << endl;
}

