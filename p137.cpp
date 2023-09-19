#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
bool is_debug;

// P.137 Jessica's reading Problem(しゃくとり法)
int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int P;
  cin >> P;
  vector<int> A;
  set<int> st;
  for (int i = 0; i < P; i++) {
    int a;
    cin >> a;
    A.push_back(a);
    st.insert(a);
  }

  int full_size = st.size();

  set<int> now;
  map<int, int> cnt;
  int ans = 1e9, start = 0, end = 0;
  while (true) {
    while (now.size() < full_size && end < P) {
      now.insert(A[end]);
      cnt[A[end++]] += 1;
    }
    // end==Pでここにくる
    if (now.size() < full_size) break;
    if (ans > end - start) {
      if (is_debug) {
        cout << end - start << endl;
        for (auto n : now) cout << n << ' ';
        cout << endl;
      }
      ans = end - start;
    }
    int s = A[start++];
    cnt[s] -= 1;
    if (cnt[s] == 0) now.erase(s);
  }
  cout << ans << endl;
}
