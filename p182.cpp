#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
bool is_debug;
using mint = static_modint<10007>;

int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int N;
  cin >> N;

  set<ll> num;
  while (N != 0) {
    num.insert(N);
    N >>= 1;
  }
  map<ll, mint> memo_even;
  map<ll, mint> memo_odd;
  for (ll n : num) {
    if (n == 1) {
      memo_even[n] = 2;
      memo_odd[n] = 0;
      continue;
    }
    if (n == 2) {
      memo_even[n] = 2;
      memo_odd[n] = 2;
      continue;
    }
    if (num.contains(n * 2)) {
      memo_even[2 * n] = memo_even[n] * memo_even[n] + memo_odd[n] * memo_odd[n];
    }
    else {

    }
  }
  
}
