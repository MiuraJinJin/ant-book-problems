#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

// P.49 Fence Repair(工夫のいる貪欲)
int main(int argc, char *argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int N;
  cin >> N;
  priority_queue<int, vector<int>, greater<int>> L;
  for (int i = 0; i < N; i++) {
    int l;
    cin >> l;
    L.push(l);
  }

  long long ans = 0;
  while (L.size() > 1) {
    int l1 = L.top();
    L.pop();
    int l2 = L.top();
    L.pop();
    ans += l1 + l2;
    L.push(l1 + l2);
    if (is_debug) cout << l1 << ' ' << l2 << endl;
  }
  cout << ans << endl;
}
