#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned int n, k;
  cin >> n >> k;
  set<int> v;
  unordered_map<int, vector<int>> m;
  int a, b;
  unsigned int cnt = 0;
  for (int i = 0; i < k; i++) {
    cin >> a >> b;
    if (m.find(a) == m.end()) {
      m.emplace(a, vector<int>());
    }
    if (m.find(b) == m.end()) {
      m.emplace(b, vector<int>());
    }
    m[a].emplace_back(b);
    m[b].emplace_back(a);
  }

  v.emplace(1);
  for (int f : m[1]) {
    if (v.find(f) == v.end()) {
      v.emplace(f);
      cnt++;
    }
    for (int ff : m[f]) {
      if (v.find(ff) == v.end()) {
        v.emplace(ff);
        cnt++;
      }
    }
  }
  cout << cnt;
  return 0;
}