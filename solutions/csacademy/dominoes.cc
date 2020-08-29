#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (auto& x : v)
    cin >> x;

  int best = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    while (j < i && v[i] - v[j] - k > i - j) {
      ++j;
    }
    best = max(best, i - j + 1 + k);
  }
  cout << best;
}