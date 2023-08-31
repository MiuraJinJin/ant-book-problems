#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int use_coins(int coin_count, int coin_value, int& A) {
  int use_count = min(coin_count, A / coin_value);
  A -= use_count * coin_value;
  return use_count;
}

// P.42 硬貨の問題(貪欲法)
int main(int argc, char *argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int C1, C5, C10, C50, C100, C500, A;
  cin >> C1 >> C5 >> C10 >> C50 >> C100 >> C500;
  cin >> A;

  int ans = 0;
  ans += use_coins(C500, 500, A);
  ans += use_coins(C100, 100, A);
  ans += use_coins(C50, 50, A);
  ans += use_coins(C10, 10, A);
  ans += use_coins(C5, 5, A);
  ans += use_coins(C1, 1, A);

  cout << ans << endl;
}
