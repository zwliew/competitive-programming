#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  uint16_t N;
  cin >> N;

  map<uint32_t, priority_queue<string, vector<string>, greater<string>>> m;

  for (size_t i = 0; i < N; i++) {
    string s;
    cin >> s;

    uint32_t hash = 0;
    for (size_t i = 0; i < s.size(); i++) {
      hash = hash ^ s[i];
    }

    if (m.find(hash) == m.end()) {
      priority_queue<string, vector<string>, greater<string>> q;
      q.emplace(s);
      m[hash] = q;
    } else {
      m[hash].emplace(s);
    }
  }

  for (auto mi : m) {
    auto q = mi.second;
    while (!q.empty()) {
      cout << q.top() << '\n';
      q.pop();
    }
  }
}