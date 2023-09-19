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
  vector<int> X;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    X.push_back(x);
  }
  sort(X.begin(), X.end());

  int ok = 0, ng = 2e9;
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    int cnt = 0;
    int now = -1e9;
    for (int i = 0; i < N; i++) if (X[i] - now >= mid) {
      now = X[i];
      cnt++;
    }
    if (cnt >= M) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}
