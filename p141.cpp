#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
bool is_debug;

const pair<int, int> scope[5] = {
  { -1, 0 },
  { 0, -1 },
  { 0, 0 },
  { 0, 1 },
  { 1, 0 },
};
int flip[16][16];
int foot[16][16];
int S[16][16];

// P.141 Fliptile
// 考え方は「P.139 Face The Right Way」と同様
// 一番上の行のみ全探索してあとは「１つ上のマスが黒の場合その下のマスはflipするしかない」ことを
// 利用する
// それを繰り返していき全て白マスにできているかを最後に確認する
int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int M, N;
  cin >> M >> N;

  for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) {
    int s;
    cin >> s;
    S[i][j] = s;
  }

  vector<vector<int>> anss;
  for (int bit = 0; bit < 1 << N; bit++) {
    fill((int*) flip, (int*) (flip + 16), 0);
    fill((int*) foot, (int*) (foot + 16), 0);
    for (int j = 0; j < N; j++) {
      if (((bit >> j) & 1) == 0) continue;
      foot[0][j] = 1;
      for (int k = 0; k < 5; k++) {
        int y = scope[k].first, x = j + scope[k].second;
        if (!(0 <= y && y < M && 0 <= x && x < N)) continue;
        flip[y][x] ^= 1;
      }
    }
    for (int i = 1; i < M; i++) {
      for (int j = 0; j < N; j++) {
        if ((S[i - 1][j] ^ flip[i - 1][j]) == 1) {
          foot[i][j] = 1;
          for (int k = 0; k < 5; k++) {
            int y = i + scope[k].first, x = j + scope[k].second;
            if (!(0 <= y && y < M && 0 <= x && x < N)) continue;
            flip[y][x] ^= 1;
          }
        }
      }
    }
    bool is_ok = true;
    for (int j = 0; j < N; j++) {
      if (S[M - 1][j] ^ flip[M - 1][j]) {
        is_ok = false;
        break;
      }
    }
    if (is_ok) {
      vector<int> candi;
      for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
          candi.push_back(foot[i][j]);
        }
      }
      anss.push_back(candi);
      if (is_debug) {
        for (int c : candi) cout << c << ' ';
        cout << endl;
      }
    }
  }
  if (anss.size() == 0) {
    cout << "IMPOSSIBLE" << endl;
  }
  else {
    sort(anss.begin(), anss.end(), [M, N](vector<int>& a, vector<int>& b) {
      for (int i = 0; i < M * N; i++) if (a[i] != b[i]) return a[i] < b[i];
      return true;
    });
    vector<int> ans = anss.front();
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        cout << ans[i * M + j];
        if (j < N - 1) cout << ' ';
        else cout << endl;
      }
    }
  }
}
