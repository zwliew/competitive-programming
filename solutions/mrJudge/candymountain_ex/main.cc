#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  if (k > n) {
    cout << 0;
    return 0;
  }

  vector<int> v(n + k + 1, 0);
  for (int ni = k; ni < n + k; ++ni) {
    cin >> v[ni];
  }

  multiset<int> s;
  for (int ni = 0; ni < k; ++ni) {
    s.emplace(v[ni]);
  }

  for (int ni = k; ni < n + k + 1; ++ni) {
    v[ni] = max(v[ni], *(s.begin()));
    s.erase(s.find(v[ni - k]));
    s.emplace(v[ni]);
  }

  cout << v[n + k];
}