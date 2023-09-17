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

  map<double, double> mp;

  const int OK_VALUE = 1000000;
  mp[0] = 0.0;
  mp[OK_VALUE] = 1.0;
  for (int i = 1; i <= M; i++) {
    map<double, double> new_mp;
    new_mp[0] = 0.0;
    new_mp[OK_VALUE] = 1.0;
    double unit = (double) OK_VALUE / (1 << i);
    for (int j = 1; j < 1 << i; j++) {
      for (int k = 0; k <= j; k++) {
        double p1 = (--mp.upper_bound(min((double) OK_VALUE, j * unit + k * unit)))->second * P;
        double p2 = (--mp.upper_bound(max(0.0, j * unit - k * unit)))->second * (1 - P);
        new_mp[j * unit] = max(new_mp[j * unit], p1 + p2);
      }
    }
    mp = new_mp;
  }

  cout << setprecision(10) << (--mp.upper_bound(X))->second << endl;
}
