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
  vector<ll> wk_W, wk_V;
  for (int i = 0; i < N; i++) {
    ll x;
    cin >> x;
    wk_W.push_back(x);
  }
  for (int i = 0; i < N; i++) {
    ll x;
    cin >> x;
    wk_V.push_back(x);
  }
  vector<pair<ll, ll>> items;
  for (int i = 0; i < N; i++) {
    items.push_back({ wk_W[i], wk_V[i] });
  }
  ll W;
  cin >> W;

  ll ans = 0;
  // N <= 20の場合普通にbit全探索
  if (N <= 20) {
    for (int bit = 0; bit < 1 << N; bit++) {
      ll candi_w = 0, candi_v = 0;
      for (int i = 0; i < N; i++) {
        if ((bit >> i) & 1) {
          candi_w += items[i].first;
          candi_v += items[i].second;
        }
      }
      if (candi_w <= W && candi_v > ans) ans = candi_v;
    }
  }
  // N > 20の場合半分全列挙
  else {
    map<ll, ll> map_A;
    int A = 20, B = N - 20;
    for (int bit = 0; bit < 1 << A; bit++) {
      ll candi_w = 0, candi_v = 0;
      for (int i = 0; i < A; i++) {
        if ((bit >> i) & 1) {
          candi_w += items[i].first;
          candi_v += items[i].second;
        }
      }
      if (map_A[candi_w] < candi_v) map_A[candi_w] = candi_v;
    }
    ll now_max = 0;
    for (auto [k, v] : map_A) {
      if (now_max < v) now_max = v;
      map_A[k] = now_max;
    }
    for (int bit = 0; bit < 1 << B; bit++) {
      ll candi_w = 0, candi_v = 0;
      for (int i = 0; i < B; i++) {
        if ((bit >> i) & 1) {
          candi_w += items[i].first;
          candi_v += items[i].second;
        }
      }
      if (candi_w <= W) {
        ll w = W - candi_w;
        ll candi = (--map_A.upper_bound(w))->second + candi_v;
        if (ans < candi) ans = candi;
      }
    }
  }
  cout << ans << endl;
}
