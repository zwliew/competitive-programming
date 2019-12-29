#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  uint64_t n, q;
  cin >> n >> q;

  priority_queue<uint64_t> maxq;
  priority_queue<uint64_t, vector<uint64_t>, greater<uint64_t>> minq;
  unordered_set<uint64_t> s;
  for (uint64_t qi = 0; qi < q; ++qi) {
    string cmd;
    cin >> cmd;

    uint64_t x;
    cin >> x;

    if (cmd == "TRANSMIT") {
      uint64_t y;
      cin >> y;

      if (minq.empty() || minq.top() > y || maxq.top() < x) {
        cout << "YES\n";
        continue;
      }

      vector<uint64_t> v;
      if (y < n / 2) {
        while (!minq.empty() && minq.top() < x) {
          if (s.find(minq.top()) == s.end()) {
            v.emplace_back(minq.top());
          }
          minq.pop();
        }

        if (minq.empty()) {
          cout << "YES\n";
          continue;
        }

        if (s.find(minq.top()) != s.end()) {
          s.erase(minq.top());
          minq.pop();
        }

        if (minq.empty() || minq.top() > y) {
          cout << "YES\n";
          continue;
        }

        cout << "NO\n";

        for (uint64_t vi : v) {
          minq.emplace(vi);
        }
      } else {
        while (!maxq.empty() && maxq.top() > y) {
          if (s.find(maxq.top()) == s.end()) {
            v.emplace_back(maxq.top());
          }
          maxq.pop();
        }

        if (maxq.empty()) {
          cout << "YES\n";
          continue;
        }

        if (s.find(maxq.top()) != s.end()) {
          s.erase(maxq.top());
          maxq.pop();
        }

        if (maxq.empty() || maxq.top() < x) {
          cout << "YES\n";
          continue;
        }

        cout << "NO\n";

        for (uint64_t vi : v) {
          maxq.emplace(vi);
        }
      }
    } else if (cmd == "WAKE") {
      s.emplace(x);

      // vector<uint64_t> v;
      // while (minq.top() != x) {
      //   v.emplace_back(minq.top());
      //   minq.pop();
      // }
      // minq.pop();
      // for (uint64_t vi : v) {
      //   minq.emplace(vi);
      // }

      // v = {};

      // while (maxq.top() != x) {
      //   v.emplace_back(maxq.top());
      //   maxq.pop();
      // }
      // maxq.pop();
      // for (uint64_t vi : v) {
      //   maxq.emplace(vi);
      // }
    } else if (cmd == "SLEEP") {
      if (s.find(x) != s.end()) {
        s.erase(x);
        continue;
      }

      minq.emplace(x);
      maxq.emplace(x);
    }
  }
}