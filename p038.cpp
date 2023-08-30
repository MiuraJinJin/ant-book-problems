#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

// P.37 迷路の最短路(BFS)
int main(int argc, char *argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int N, M;
  cin >> N >> M;
  bool field[N][M];
  pair<int, int> start, goal;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < M; j++) {
      if (s[j] == 'S') start = {i, j};
      if (s[j] == 'G') goal = {i, j};
      field[i][j] = s[j] == '.' || s[j] == 'G';
    }
  }

  int steps[N][M];
  fill((int*) steps, (int*) (steps + N), N * M + 1);
  steps[start.first][start.second] = 0;

  deque<pair<int, int>> dq;
  dq.push_back(start);

  while (!dq.empty()) {
    pair<int, int> p = dq.front();
    dq.pop_front();
    int i = p.first, j = p.second;
    int now_step = steps[i][j];
    if (i - 1 >= 0 && field[i - 1][j] && steps[i - 1][j] > now_step + 1) {
      steps[i - 1][j] = now_step + 1;
      dq.push_back({i - 1, j});
    }
    if (i + 1 < N && field[i + 1][j] && steps[i + 1][j] > now_step + 1) {
      steps[i + 1][j] = now_step + 1;
      dq.push_back({i + 1, j});
    }
    if (j - 1 >= 0 && field[i][j - 1] && steps[i][j - 1] > now_step + 1) {
      steps[i][j - 1] = now_step + 1;
      dq.push_back({i, j - 1});
    }
    if (j + 1 < N && field[i][j + 1] && steps[i][j + 1] > now_step + 1) {
      steps[i][j + 1] = now_step + 1;
      dq.push_back({i, j + 1});
    }
  }
  cout << steps[goal.first][goal.second] << endl;
}
