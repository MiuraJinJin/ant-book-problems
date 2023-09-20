#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
bool is_debug;

int memo[5001];

// P.139 Face The Right Way
int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int N;
  cin >> N;
  string s;
  cin >> s;
  // Back: 0, Front: 1
  vector<int> S;
  for (char c : s) S.push_back(c == 'B' ? 0 : 1);

  vector<pair<int, int>> MK;
  for (int i = 0; i < N; i++) {
    fill((int*) memo, (int*) (memo + 5001), 0);
    int now = 0;
    for (int j = 0; j < N - i; j++) {
      if ((S[j] + now) % 2 == 0) {
        now = (now + 1) % 2;
        memo[j] = 1;
      }
      if (j - i >= 0 && memo[j - i] == 1) now--;
    }
    bool ok = true;
    for (int j = N - i; j < N; j++) {
      if ((S[j] + now) % 2 == 0) ok = false;
    }
    if (ok) {
      MK.push_back({ i + 1, accumulate(begin(memo), end(memo), 0) });
    }
  }
  sort(MK.begin(), MK.end(), [](pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second; });

  if (is_debug) {
    for (auto [m, k] : MK) cout << m << ' ' << k << endl;
  }
  cout << MK.front().second << ' ' << MK.front().first << endl;
}
