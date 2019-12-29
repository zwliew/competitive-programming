#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  uint32_t n, k;
  cin >> n >> k;

  queue<int64_t> q;
  for (uint32_t ni = 0; ni < n; ++ni) {
    int64_t t;
    cin >> t;
    q.emplace(t);
  }

  int64_t ms = 0;
  int64_t s = 0;
  uint32_t kc = 0;
  priority_queue<int64_t> pq;

  while (!q.empty()) {
    while (kc >= k) {
      int64_t pt = pq.top();
      pq.pop();
      s += pt;
      --kc;
    }

    int64_t t = q.front();
    q.pop();
    if (t >= 0) {
      s += t;
    } else {
      ++kc;
      pq.emplace(t);
    }

    ms = max(s, ms);
  }

  cout << ms;
  return 0;
}