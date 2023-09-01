#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

// P.45 Best Cow Line
int main(int argc, char* argv[]) {
  bool is_debug = string(argv[0]) == "./test.out";

  int N;
  cin >> N;
  string S;
  cin >> S;
  deque<char> dq;
  for (char c : S) dq.push_back(c);
  string T;
  for (int i = 0; i < N; i++) {
    char head, tail;
    for (int j = 0; j < dq.size(); j++) {
      head = dq[j];
      tail = dq[dq.size() - 1 - j];
      if (head != tail) break;
    }
    if (head <= tail) {
      T.push_back(dq.front());
      dq.pop_front();
    }
    else {
      T.push_back(dq.back());
      dq.pop_back();
    }
  }
  cout << T << endl;
}
