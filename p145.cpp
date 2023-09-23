#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
bool is_debug;

// P.145 Physics Experiment
int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int N, H, R, T;
  cin >> N >> H >> R >> T;

  double g = 10.0;
  vector<double> heights;
  for (int i = 0; i < N; i++) {
    // 高さをiごとに変えて計算するやり方はNG
    // ボールが下にある分オフセットができるので
    // i = 0と同一のhで考え、最後にi * (2 * R)を加算すべき
    // double h = H + i * (2 * R);
    double t = T - i;
    if (t < 0.0) {
      heights.push_back(H + i * 2 * R * 0.01);
      continue;
    }
    // h動くのにかかる時間
    double t1 = sqrt((2 * H) / g);
    // 跳ね返り回数
    int cnt = (int) (t / t1);
    t -= cnt * t1;
    // 落下中か跳ね上がり中か
    // 落下中
    if (cnt % 2 == 0) {
      heights.push_back(H - (g * t * t) / 2.0 + i * 2 * R * 0.01);
    }
    // 跳ね上がり中
    else {
      heights.push_back(H - (g * pow(t1 - t, 2.0)) / 2.0 + i * 2 * R * 0.01);
    }
  }
  sort(heights.begin(), heights.end());
  cout << fixed << setprecision(2);
  for (int i = 0; i < N; i++) {
    cout << heights[i];
    if (i != N - 1) cout << ' ';
    else cout << endl;
  }
}
