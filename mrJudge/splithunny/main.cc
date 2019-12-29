#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool contains(set<T> m, T k) {
 return m.find(k) != m.end();
}
int main() {
  int r,c;
  cin >> r >> c;
  set<pair<int, int>> h,s;
  for (auto i = 0; i < r; i++) {
    string s;
    cin >> s;
    for (int i2 = 0; i2 < s.size(); i2++) {
      if (s[i2] == 'H') {
        h.emplace(make_pair(i, i2));
      }
    }
  }

  unsigned int cnt = 0;
  for (auto c : h) {
    if (contains(s, c)) {
      continue;
    }
    queue<pair<int,int>> q;
    q.emplace(c);
    while (!q.empty()) {
      auto qc = q.front();
      q.pop();
      if (s.find(qc) != s.end()) {
        continue;
      }
      s.emplace(qc);
      auto qcp = make_pair(qc.first - 1, qc.second);
      if (h.find(qcp) != h.end()) {
        q.emplace(qcp);
      }
      qcp = make_pair(qc.first + 1, qc.second);
      if (h.find(qcp) != h.end()) {
        q.emplace(qcp);
      }
      qcp = make_pair(qc.first, qc.second+ 1);
      if (h.find(qcp) != h.end()) {
        q.emplace(qcp);
      }
      qcp = make_pair(qc.first, qc.second- 1);
      if (h.find(qcp) != h.end()) {
        q.emplace(qcp);
      }
    }
    ++cnt;
  }

  cout << "Oh, bother. There are " << cnt << " pools of hunny.";
  return 0;
}