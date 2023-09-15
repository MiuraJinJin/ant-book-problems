#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
bool is_debug;

// P.113 区間内の素数の個数
// エラトステネスのふるいの1回の「素数でない値の打ち消し」のO(loglogN)程度になることを利用
int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  long long A, B;
  cin >> A >> B;
  map<long long, bool> prime;
  for (long long i = A; i < B; i++) {
    prime[i] = true;
  }
  for (long long i = 2; i * i < B; i++) {
    for (long long j = (A % i == 0) ? A : A - A % i + i; j <= B; j += i) {
      prime[j] = false;
    }
  }
  if (is_debug) {
    for (auto [k, v] : prime) if (v) cout << k << ' ';
    cout << endl;
  }
  int ans = 0;
  for (long long i = A; i < B; i++) {
    ans += prime[i];
  }
  cout << ans << endl;
}
