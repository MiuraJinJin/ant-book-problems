#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
bool is_debug;

bool check_prime(long long n) {
  bool is_prime = n != 1;
  for (long long i = 2; is_prime && i * i <= n; i++) {
    if (n % i == 0) is_prime = false;
  }
  return is_prime;
}

vector<long long> make_divisors(long long n) {
  vector<long long> divisors;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      divisors.push_back(i);
      if (i != n / i) divisors.push_back(n / i);
    }
  }
  sort(divisors.begin(), divisors.end());
  return divisors;
}

map<long long, int> make_prime_factors(long long n) {
  map<long long, int> prime_factors;
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      prime_factors[i]++;
      n /= i;
    }
  }
  // nは最後に1または素数になる
  if (n != 1) prime_factors[n]++;
  return prime_factors;
}

// P.110 素数判定
int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  long long N;
  cin >> N;

  cout << (check_prime(N) ? "Yes" : "No") << endl;

  if (is_debug) {
    for (long long n : make_divisors(N)) cout << n << ' ';
    cout << endl;
    for (auto [k, v] : make_prime_factors(N)) cout << k << ',' << v << ' ';
    cout << endl;
  }
}
