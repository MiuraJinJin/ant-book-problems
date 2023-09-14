#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
bool is_debug;

const int eratosthenes_length = 10000000;
bool eratosthenes[eratosthenes_length + 1];
void init_eratosthene() {
  for (int i = 2; i <= eratosthenes_length; i++) eratosthenes[i] = true;
  for (int i = 0; i <= eratosthenes_length; i++) {
    if (!eratosthenes[i]) continue;
    for (int j = 2 * i; j <= eratosthenes_length; j += i) eratosthenes[j] = false;
  }
}

// P.111 素数の個数(エラトステネスのふるい)
int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int N;
  cin >> N;

  init_eratosthene();
  int ans = 0;
  for (int i = 1; i <= N; i++) if (eratosthenes[i]) ans++;
  cout << ans << endl;
}
