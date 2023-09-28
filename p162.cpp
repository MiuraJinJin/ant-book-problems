#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
bool is_debug;

// P.162 バブルソートの交換回数
int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int N;
  cin >> N;
  vector<int> A;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }

  fenwick_tree<ll> bit(N);

  int ans = 0;
  for (int a : A) {
    ans += bit.sum(a - 1, N);
    bit.add(a - 1, 1);
  }
  cout << ans << endl;
}
