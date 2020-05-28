#include <bits/stdc++.h>
using namespace std;
int main() {
  uint16_t N, M;
  cin >> N >> M;

  unordered_map<int, int> m;
  for (size_t i = 0; i < N; i++) {
    uint16_t ni;
    cin >> ni;

    if (m.find(ni) == m.end()) {
      m.emplace(ni, 1);
    } else {
      m[ni]++;
    }
  }

  int curmax = 0;
  for (auto mi : m) {
    if (mi.second < M && curmax < mi.second) {
      curmax = mi.second;
    }
  }

  cout << curmax;
}