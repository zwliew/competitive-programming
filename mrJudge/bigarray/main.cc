#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  uint32_t n;
  uint64_t k;
  cin >> n >> k;

  vector<pair<uint32_t, uint32_t>> v(n);
  for (uint32_t i = 0; i < n; ++i) {
    uint32_t a, b;
    cin >> a >> b;

    v[i] = make_pair(a, b);
  }

  sort(v.begin(), v.end());

  for (auto p : v) {
    if (p.second >= k) {
      cout << p.first;
      return 0;
    } else {
      k -= p.second;
    }
  }
}