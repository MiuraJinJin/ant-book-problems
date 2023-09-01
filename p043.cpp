#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

// P.43 区間スケジューリング問題(終了順が最適)
int main(int argc, char* argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int N;
  cin >> N;
  vector<int> S;
  for (int i = 0; i < N; i++) {
    int s;
    cin >> s;
    S.push_back(s);
  }
  vector<int> T;
  for (int i = 0; i < N; i++) {
    int t;
    cin >> t;
    T.push_back(t);
  }
  vector<pair<int, int>> tasks;
  for (int i = 0; i < N; i++) {
    tasks.push_back({ S[i], T[i] });
  }

  sort(tasks.begin(), tasks.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second; });

  int ans = 0, now = 0;
  for (pair<int, int> task : tasks) {
    if (now < task.first) {
      now = task.second;
      ans++;
    }
  }
  cout << ans << endl;
}
