#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

// P.47 Saruman's Army
int main(int argc, char* argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int N, R;
  cin >> N >> R;
  vector<int> X;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    X.push_back(x);
  }

  sort(X.begin(), X.end());

  vector<int> left{ X.front() }, pointed{ X.front() };
  for (int x : X) {
    if (x - left.back() <= R) {
      pointed[pointed.size() - 1] = x;
    }
    else if (x - pointed.back() > R) {
      left.push_back(x);
      pointed.push_back(x);
    }
  }
  if (is_debug) for (int p : pointed) cout << p << " ";
  cout << pointed.size() << endl;
}
