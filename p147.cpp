#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
bool is_debug;

int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int N;
  cin >> N;
  vector<ll> A, B, C, D;
  for (int i = 0; i < N; i++) {
    ll x;
    cin >> x;
    A.push_back(x);
  }
  for (int i = 0; i < N; i++) {
    ll x;
    cin >> x;
    B.push_back(x);
  }
  for (int i = 0; i < N; i++) {
    ll x;
    cin >> x;
    C.push_back(x);
  }
  for (int i = 0; i < N; i++) {
    ll x;
    cin >> x;
    D.push_back(x);
  }

  map<ll, int> CD;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      CD[C[i] + D[j]] += 1;

  int ans = 0;
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
    ll ab = A[i] + B[j];
    ans += CD[-ab];
  }

  cout << ans << endl;
}
