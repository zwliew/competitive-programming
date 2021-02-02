#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE "milkvisits"

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

  int N;
  int64_t K;
  cin >> N >> K;
  vector<int64_t> A(N);

  int64_t ans = 0;
  monotonic_queue<int64_t> mx;
  monotonic_queue<int64_t, greater<int64_t>> mn;
  for (int r = 0, l = 0; r < N; ++r) {
    cin >> A[r];
    mx.push(A[r]);
    mn.push(A[r]);
    while (mx.top() - mn.top() > K) {
      mx.pop();
      mn.pop();
      ++l;
    }
    ans += r - l + 1;
  }
  cout << ans;
}
