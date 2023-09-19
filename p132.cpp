#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
bool is_debug;

// P.132 平均最大化(Xの値が評価の中に組み込まれるタイプに二分探索)
int main(int argc, char* argv[]) {
  is_debug = string(argv[0]) == "./test.out";

  int N, K;
  cin >> N >> K;
  vector<pair<double, double>> items;
  for (int i = 0; i < N; i++) {
    double w, v;
    cin >> w >> v;
    items.push_back({ w, v });
  }

  double ok = 0, ng = 1e12;
  while (ng - ok > 0.01) {
    double mid = (ng + ok) / 2;
    vector<double> points;
    for (int i = 0; i < N; i++) {
      auto [w, v] = items[i];
      points.push_back(v - mid * w);
    }
    sort(points.rbegin(), points.rend());
    double point = 0;
    for (int i = 0; i < K; i++) point += points[i];
    if (point >= 0) ok = mid;
    else ng = mid;
  }

  cout << setprecision(2) << ok << endl;
}
