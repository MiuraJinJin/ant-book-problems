#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
bool is_debug;

// P.135 Subsequence(しゃくとり法)
int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int N, S;
  cin >> N >> S;
  vector<int> A;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }

  int i = 0, ans = 1e9, now = 0;
  deque<int> que;
  while (true) {
    while (now < S && i < N) {
      que.push_back(A[i]);
      now += A[i++];
    }
    // nowがS未満の場合最後まで読み込み済み
    if (now < S) break;
    if (now >= S && ans > que.size()){
      if (is_debug) {
        for (int q : que) cout << q << ' ';
        cout << endl;
      }
      ans = que.size();
    }
    now -= que.front();
    que.pop_front();
  }
  if (ans == 1e9) ans = 0;
  cout << ans << endl;
}
