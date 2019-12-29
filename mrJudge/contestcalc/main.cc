#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  uint32_t n;
  cin >> n;

  unordered_map<string, uint32_t> m;
  for (uint32_t ni = 0; ni < n; ++ni) {
    string s;
    uint32_t ms;
    cin >> s >> ms;
    m[s] = ms;
  }

  uint32_t c;
  cin >> c;

  uint32_t s = 0;
  for (uint32_t ci = 0; ci < c; ++ci) {
    string x;
    cin >> x;
    s += m[x];
  }

  cout << round(s / c);
}