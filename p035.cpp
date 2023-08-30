#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int N, M;
bool checked[101][101];
bool field[101][101];
void recur(int x, int y) {
  checked[x][y] = true;
  for (int i = -1; i <= 1; i++) for (int j = -1; j <= 1; j++) {
    if (i == 0 && j == 0) continue;
    if (!(0 <= x + i && x + i < N && 0 <= y + j && y + j < M)) continue;
    if (checked[x + i][y + j]) continue;
    if (!field[x + i][y + j]) continue;
    recur(x + i, y + j);
  }
}

// P.35 Lake Counting
int main(int argc, char* argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < M; j++) {
      field[i][j] = s[j] == 'W';
    }
  }

  int count = 0;
  for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
    if (!checked[i][j] && field[i][j]) {
      count++;
      recur(i, j);
    }
  }
  cout << count << endl;
}
