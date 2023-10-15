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
}
