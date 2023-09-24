#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
bool is_debug;

template<typename T>
vector<T> concat_vector(vector<T>& a, vector<T>& b) {
  vector<T> res(a);
  res.insert(res.end(), b.begin(), b.end());
  return res;
}

int field[6 * 500][6 * 500];

// P.150 領域の個数(座標圧縮)
int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int W, H, N;
  cin >> W >> H >> N;
  vector<int> X1, X2, Y1, Y2;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    X1.push_back(--x);
  }
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    X2.push_back(--x);
  }
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    Y1.push_back(--x);
  }
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    Y2.push_back(--x);
  }
  vector<int> X = concat_vector(X1, X2);
  if (is_debug) {
    for (auto x : X) {
      cout << x << ' ';
    }
    cout << endl;
  }
  vector<int> xx;
  for (auto x : X) for (int i = -1; i <= 1; i++) if (0 <= x + i && x + i < W) xx.push_back(x + i);
  map<int, int> to_short_X, to_long_X;
  for (auto x : xx) to_short_X[x] = 1;
  int max_short_X = 0;
  {
    int i = 0;
    for (auto [k, v] : to_short_X) {
      to_long_X[i] = k;
      to_short_X[k] = i++;
    }
    max_short_X = i;
  }

  vector<int> Y = concat_vector(Y1, Y2);
  vector<int> yy;
  for (auto y : Y) for (int i = -1; i <= 1; i++) if (0 <= y + i && y + i < H) yy.push_back(y + i);
  map<int, int> to_short_Y, to_long_Y;
  for (auto y : yy) to_short_Y[y] = 1;
  int max_short_Y = 0;
  {
    int i = 0;
    for (auto [k, v] : to_short_Y) {
      to_long_Y[i] = k;
      to_short_Y[k] = i++;
    }
    max_short_Y = i;
  }
  if (is_debug) {
    for (auto [k, v] : to_short_Y) {
      cout << k << ':' << v << endl;
    }
  }

  for (int i = 0; i < N; i++) {
    int x1 = min(to_short_X[X1[i]], to_short_X[X2[i]]);
    int x2 = max(to_short_X[X1[i]], to_short_X[X2[i]]);
    int y1 = min(to_short_Y[Y1[i]], to_short_Y[Y2[i]]);
    int y2 = max(to_short_Y[Y1[i]], to_short_Y[Y2[i]]);
    if (is_debug) {
      cout << x1 << ' ' << x2 << endl;
      cout << y1 << ' ' << y2 << endl;
    }
    // xかyのどちらかは範囲が1なので計算量的に問題ない
    for (int x = x1; x <= x2; x++) {
      for (int y = y1; y <= y2; y++) {
        field[x][y] = 1;
      }
    }
  }

  if (is_debug) {
    for (int j = 0; j < max_short_Y; j++) {
      for (int i = 0; i < max_short_X; i++) {
        cout << field[i][j] << ' ';
      }
      cout << endl;
    }
  }
  int ans = 0;
  for (int i = 0; i < max_short_X; i++) {
    for (int j = 0; j < max_short_Y; j++) {
      if (field[i][j] == 1) continue;
      ans++;
      deque<pair<int, int>> dfs;
      dfs.push_back({ i, j });
      field[i][j] = 1;
      while (!dfs.empty()) {
        auto [x, y] = dfs.back();
        dfs.pop_back();
        for (int xx = -1; xx <= 1; xx++) {
          for (int yy = -1; yy <= 1; yy++) {
            if (abs(xx) + abs(yy) != 1) continue;
            if (!(0 <= x + xx && x + xx < max_short_X && 0 <= y + yy && y + yy < max_short_Y)) continue;
            if (field[x + xx][y + yy] == 0) {
              field[x + xx][y + yy] = 1;
              dfs.push_back({ x + xx, y + yy });
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
}
