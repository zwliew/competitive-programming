#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  uint32_t n;
  cin >> n;

  unordered_set<string> s;
  for (uint32_t ni = 0; ni < n; ++ni) {
    string x;
    cin >> x;
    s.emplace(x);
  }

  cout << s.size();
}