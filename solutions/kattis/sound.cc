#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE "milkvisits"

#include <deque>
#include <functional>

template <class T, class Compare = std::less<T>>
class monotonic_queue {
 private:
  std::deque<std::pair<T, int>> q;
  const Compare cmp = Compare();

 public:
  void push(const T val) {
    int cnt = 1;
    while (q.size() && cmp(q.back().first, val)) {
      cnt += q.back().second;
      q.pop_back();
    }
    q.emplace_back(val, cnt);
  }

  void pop() {
    --q.front().second;
    if (!q.front().second) {
      q.pop_front();
    }
  }

  T top() const { return q.front().first; }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N, M, C;
  cin >> N >> M >> C;
  vector<int> samples(N);
  // multiset<int> window;
  monotonic_queue<int, greater<int>> mn;
  monotonic_queue<int> mx;
  bool none = true;
  for (int r = 0; r < N; ++r) {
    cin >> samples[r];
    mx.push(samples[r]);
    mn.push(samples[r]);
    if (r >= M) {
      mn.pop();
      mx.pop();
    }
    if (r >= M - 1 && mx.top() - mn.top() <= C) {
      cout << r - M + 2 << "\n";
      none = false;
    }
  }
  if (none) {
    cout << "NONE";
  }
}
