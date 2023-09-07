#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

// P.73 Expedition(プライオリティキューを用いる貪欲)
int main(int argc, char* argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int N, L, P;
  cin >> N >> L >> P;
  vector<int> A, B;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }
  map<int, int> gas_station;
  for (int i = 0; i < N; i++) {
    int b;
    cin >> b;
    gas_station[A[i]] += b;
  }

  // 燃料が0になった地点にガソリンスタンドがある場合そこから補給して続行可能なようです
  int ans = 0;
  priority_queue<int> gas;
  vector<int> debug_vec;
  for (int i = 1; i < L; i++) {
    P--;
    if (gas_station[i] > 0) gas.push(gas_station[i]);
    if (P == 0 && !gas.empty()) {
      P += gas.top();
      debug_vec.push_back(gas.top());
      gas.pop();
      ans++;
    }
    if (P == 0) {
      ans = -1;
      break;
    }
  }

  if (is_debug) {
    for (int i : debug_vec) cout << i << ' ';
    cout << endl;
  }

  cout << ans << endl;
}
