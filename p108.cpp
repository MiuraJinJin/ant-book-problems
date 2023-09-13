#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

bool is_debug;

// 拡張ユークリッドの互除法
// 戻り値: gcd(a, b)
// ax + by = gcd(a, b) を満たす (x, y) が格納される
int ext_euclid(int a, int b, int& x, int& y) {
  if (is_debug) cout << "call: " <<  a << ' ' << b << ' ' << x << ' ' << y << endl;
  if (b == 0) {
    x = 1;
    y = 0;
    if (is_debug) cout << "return: " <<  a << ' ' << b << ' ' << x << ' ' << y << ' ' << a << endl;
    return a;
  }
  int d = ext_euclid(b, a % b, y, x);
  y -= (a / b) * x; // (a / b) は a = q * b + r (r = a % b)とした時のq
  if (is_debug) cout << "return: " <<  a << ' ' << b << ' ' << x << ' ' << y << ' ' << d << endl;
  return d;
}

// P.108 双六（拡張ユークリッドの互除法で一次方程式をとく）
int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  // long long x = -1, y = -1;
  // cout << ext_euclid(111, 30, x, y) << endl;
  int A, B, X = -1, Y = -1;
  cin >> A >> B;
  int d = ext_euclid(A, B, X, Y);

  if (d != 1) cout << -1 << endl;
  // a, b, -a, -b
  else {
    int a = max(0, X), b = max(0, Y), aa = max(0, -X), bb = max(0, -Y);
    cout << a << ' ' << b << ' ' << aa << ' ' << bb << endl;
  }
}
