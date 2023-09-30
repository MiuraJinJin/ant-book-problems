#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
bool is_debug;

int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int N, M;
  cin >> N >> M;
  vector<ll> A;
  for (int i = 0; i < N; i++) {
    ll a;
    cin >> a;
    A.push_back(a);
  }

  int n = sqrt(N);

  vector<vector<ll>> sp(1, vector<ll>());
  for (ll a : A) {
    if (sp.back().size() == n) sp.push_back(vector<ll>());
    sp.back().push_back(a);
  }

  vector<vector<ll>> sp_sorted;
  for (vector<ll> s : sp) {
    vector<ll> s_sorted(s);
    sp_sorted.push_back(s_sorted);
  }

  for (int i = 0; i < M; i++) {
    ll a, b, k;
    cin >> a >> b >> k;
    ll top = N - 1, bottom = -1;
    while (top - bottom > 1) {
      
    }
  }
}
