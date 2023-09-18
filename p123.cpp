#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
bool is_debug;

// P.123 Millionaire
// mapのアクセスおよびupper_boundがO(logN)になるため
// O(M4^MlogN)程度のアクセス回数になりM=15の条件では実行時間が非常にかかる
// ※4^Mは2^M*2^Mから
// そのためlogNを外すために予めdp[1<<M+1]の配列を作りupper_boundを使わずに
// 前回の結果にインデックスアクセスできるようにするとO(M4^M)まで抑えることができる
int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int M;
  cin >> M;
  double P;
  cin >> P;
  int X;
  cin >> X;

  map<double, double> mp;

  const double OK_VALUE = 1000000;
  mp[0.0] = 0.0;
  mp[OK_VALUE] = 1.0;
  for (int i = 1; i <= M; i++) {
    map<double, double> new_mp;
    new_mp[0] = 0.0;
    new_mp[OK_VALUE] = 1.0;
    double unit = OK_VALUE / (1 << i);
    for (int j = 1; j < 1 << i; j++) {
      for (int k = 0; k <= j; k++) {
        double p1 = (--mp.upper_bound(j * unit + k * unit))->second * P;
        double p2 = (--mp.upper_bound(j * unit - k * unit))->second * (1 - P);
        new_mp[j * unit] = max(new_mp[j * unit], p1 + p2);
        // 勝てばOK_VALUEを超える額を賭けた場合それ以上を賭ける必要がないためbreak
        if (OK_VALUE < j * unit + k * unit) break;
      }
    }
    mp = new_mp;
  }

  cout << setprecision(10) << (--mp.upper_bound(X))->second << endl;
}
