#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  vector<ll> p1(n + 1, 0), p2(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> p1[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> p2[i];
  }

  for (int pi = 1; pi < n + 1; ++pi) {
    p1[pi] += max(p1[pi - 1], p2[pi - 1] - k);
    p2[pi] += max(p2[pi - 1], p1[pi - 1] - k);
  }

  cout << max(p1[n], p2[n]);
}