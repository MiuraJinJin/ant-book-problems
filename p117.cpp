#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
bool is_debug;

// P.117 Minimum Scalar Product
int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int N;
  cin >> N;
  vector<int> X, Y;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    X.push_back(x);
  }
  for (int i = 0; i < N; i++) {
    int y;
    cin >> y;
    Y.push_back(y);
  }

  int wk = 0;
  vector<int> anss;
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  wk = 0;
  for (int i = 0; i < N; i++) wk += X[i] * Y[i];
  anss.push_back(wk);
  sort(X.begin(), X.end(), greater<int>());
  sort(Y.begin(), Y.end());
  wk = 0;
  for (int i = 0; i < N; i++) wk += X[i] * Y[i];
  anss.push_back(wk);
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end(), greater<int>());
  wk = 0;
  for (int i = 0; i < N; i++) wk += X[i] * Y[i];
  anss.push_back(wk);
  sort(X.begin(), X.end(), greater<int>());
  sort(Y.begin(), Y.end(), greater<int>());
  wk = 0;
  for (int i = 0; i < N; i++) wk += X[i] * Y[i];
  anss.push_back(wk);

  if (is_debug) {
    for (int ans : anss) cout << ans << ' ';
    cout << endl;
  }
  cout << *min_element(anss.begin(), anss.end()) << endl;
}
