#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
bool is_debug;

// P.129 Cable master
int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int N, K;
  cin >> N >> K;
  vector<int> L;
  for (int i = 0; i < N; i++) {
    double l;
    cin >> l;
    L.push_back(l * 100);
  }

  int ng = 1e9, ok = 0;
  while (ng - ok > 1) {
    int mid = (ng + ok) / 2;
    int k = 0;
    for (int l : L) k += (l / mid);
    if (k >= K) ok = mid;
    else ng = mid;
  }

  cout << fixed <<  setprecision(2) << (ok / 100.0) << endl;
}
