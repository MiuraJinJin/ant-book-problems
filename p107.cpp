#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

// ユークリッドの互除法で最大公約数を求める
// 計算量はO(log(max(a, b)))
int euclid(int a, int b) {
  if (b == 0) return a;
  return euclid(b, a % b);
}

// P.107 線分上の格子点の個数(gcd)
int main(int argc, char* argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int X1, Y1, X2, Y2;
  cin >> X1 >> Y1 >> X2 >> Y2;

  // gcdは互いのすべての約数からなる合成数なので
  // それで割れば互いに素になることを利用する
  // int ans = abs(euclid(X2 - X1, Y2 - Y1)) - 1;
  int ans = abs(gcd(X2 - X1, Y2 - Y1)) - 1;

  cout << ans << endl;
}
