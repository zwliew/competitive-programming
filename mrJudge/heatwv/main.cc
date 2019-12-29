#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t, c, ts, te;
  cin >> t >> c >> ts >> te;
  vector<unordered_map<int, int>> v(t + 1, unordered_map<int, int>());
  unordered_set<int> s;
  for (int i = 0; i < c; i++) {
    int r1i, r2i, ci;
    cin >> r1i >> r2i >> ci;
    auto p = v[r1i].find(r2i);
    if (p == v[r1i].end() || p->second > ci) {
      v[r1i].insert_or_assign(r2i, ci);
      v[r2i].insert_or_assign(r1i, ci);
    }
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      q;
  q.emplace(make_pair(0, ts));
  while (!q.empty()) {
    auto cur = q.top();
    q.pop();
    int curc = cur.first;
    int curt = cur.second;
    if (curt == te) {
      cout << curc;
      return 0;
    }
    s.emplace(curt);
    for (auto n : v[curt]) {
      int nt = n.first;
      int nc = n.second;
      if (s.find(nt) != s.end()) {
        continue;
      }
      q.emplace(make_pair(curc + nc, nt));
    }
  }
}