#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  vector<int> v(n + k + 1, 0);
  for (int ni = k; ni < n + k; ++ni) {
    cin >> v[ni];
  }

  for (int ni = k; ni < n + k + 1; ++ni) {
    int cm = INT_MAX;
    for (int ki = 1; ki <= k; ++ki) {
      cm = min(v[ni - ki], cm);
    }
    v[ni] = max(v[ni], cm);
  }

  cout << v[n + k];
}