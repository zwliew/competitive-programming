#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int p, w;
  cin >> p >> w;
  unordered_map<int, vector<int>> m;
  while (w--) {
    int s, e;
    cin >> s >> e;
    m[e].emplace_back(s);
  }

  vector<int> t(p, 0);
  for (int pi = 1; pi < p; ++pi) {
    int ct = t[pi - 1];
    if (m.find(pi) != m.end()) {
      for (int vi : m[pi]) {
        ct = min(t[vi], ct);
      }
    }
    t[pi] = ct + 1;
  }

  cout << t[p - 1];
}