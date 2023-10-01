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
    sort(s_sorted.begin(), s_sorted.end());
    sp_sorted.push_back(s_sorted);
  }

  vector<ll> sorted_A(A);
  sort(sorted_A.begin(), sorted_A.end());

  for (int i = 0; i < M; i++) {
    ll a, b, k;
    cin >> a >> b >> k;
    ll ok = N - 1, ng = -1;
    while (ok - ng > 1) {
      ll mid = (ok + ng) / 2;
      ll sp_start = -1, sp_end = -1;
      for (int i = 0; i * n < N; i++) {
        if (sp_start == -1 && i * n >= a) sp_start = i;
        if (sp_end == -1 && i * n >= b) sp_end = i;
      }
      int wk = 0;
      for (int i = a; i < sp_start * n; i++) if (sorted_A[mid] >= A[i]) wk++;
      for (int i = (sp_end - 1) * n; i < b; i++) if (sorted_A[mid] >= A[i]) wk++;

      for (int i = sp_start; i < sp_end; i++) {
        wk += upper_bound(sp_sorted[i].begin(), sp_sorted[i].end(), sorted_A[mid]) - sp_sorted[i].begin();
        if (is_debug) {
          cout << upper_bound(sp_sorted[i].begin(), sp_sorted[i].end(), sorted_A[mid]) - sp_sorted[i].begin() << endl;
        }
      }
      if (is_debug) {
        cout << wk << ' ' << ok << ' ' << ng << endl;
      }
      if (wk > k) ng = mid;
      else ok = mid;
    }
    cout << ok << endl;
  }
}
