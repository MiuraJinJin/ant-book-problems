#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
bool is_debug;

// 素数判定O(√N)
bool check_prime(long long n) {
  bool is_prime = n != 1;
  for (long long i = 2; is_prime && i * i <= n; i++) {
    if (n % i == 0) is_prime = false;
  }
  return is_prime;
}

// P.114 Charmichael Numbers(繰り返し二乗法)
int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int N;
  cin >> N;

  if (check_prime(N)) {
    if (is_debug) cout << "No prime" << endl;
    cout << "No" << endl;
    return 0;
  }
  for (int i = 2; i < N; i++) {
    int bit = N;
    long long n = 1, pw = i;
    while (bit) {
      if (bit & 1) n = (n * pw) % N;
      pw = (pw * pw) % N;
      bit >>= 1;
    }
    if (is_debug) cout << i << ' ' << n << ' ' << pw << ' ' << bit << endl;
    if (n != i) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
