#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  uint32_t n;
  cin >> n;

  priority_queue<int32_t> maxq;
  priority_queue<int32_t, vector<int32_t>, greater<int32_t>> minq;
  for (uint32_t ni = 0; ni < n; ++ni) {
    string s;
    cin >> s;

    if (s == "PUSH") {
      int32_t x;
      cin >> x;

      if (!minq.empty() && x > minq.top()) {
        minq.emplace(x);
        if (maxq.size() < minq.size()) {
          maxq.emplace(minq.top());
          minq.pop();
        }
      } else {
        maxq.emplace(x);
        if (maxq.size() > minq.size() + 1) {
          minq.emplace(maxq.top());
          maxq.pop();
        }
      }
    } else if (s == "POP") {
      maxq.pop();
      if (maxq.size() < minq.size()) {
        maxq.emplace(minq.top());
        minq.pop();
      }
    }
  }

  while (!maxq.empty()) {
    minq.emplace(maxq.top());
    maxq.pop();
  }
  while (!minq.empty()) {
    cout << minq.top() << ' ';
    minq.pop();
  }
}