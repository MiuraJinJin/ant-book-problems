#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
bool is_debug;


int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int M;
  cin >> M;
  double P;
  cin >> P;
  int X;
  cin >> X;

  map<ll, double> mp;
  const int OK_VALUE = 1000000;
  mp[-1e18] = 0.0;
  mp[OK_VALUE] = 1.0;
  for (int i = 1; i <= M; i++) {
    map<ll, double> new_mp;
    new_mp[-1e18] = 0.0;
    new_mp[OK_VALUE] = 1.0;
    int unit = OK_VALUE / (1 << i);
    for (int j = 1; j < 1 << i; j++) {
      double p1 = mp.lower_bound(j * unit + unit)->second * P;
      double p2 = mp.lower_bound(j * unit - unit)->second * (1 - P);
      if (is_debug) {
        for (auto [k, v] : mp) cout << k << ':' << v << endl;
        cout << j * unit << ' ' << mp.lower_bound(j * unit - unit)->first << endl;
        cout << j * unit << ' ' << mp.lower_bound(-1000000000000000000LL)->first << endl;
      }
      new_mp[j * unit] = p1 + p2;
    }
    mp = new_mp;
  }
  if (is_debug) {
    for (auto [k, v] : mp) cout << k << ' ' << v << endl;
  }
  cout << mp.lower_bound(X)->second << endl;
}
