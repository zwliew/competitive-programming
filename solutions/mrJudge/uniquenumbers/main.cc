#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  uint32_t n;
  cin >> n;

  uint32_t cnt = 0;
  unordered_set<int32_t> s;
  for (uint32_t ni = 0; ni < n; ++ni) {
    int32_t x;
    cin >> x;
    if (s.find(x) == s.end()) {
      ++cnt;
      s.emplace(x);
    }
  }

  cout << cnt;
}