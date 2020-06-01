#include <iostream>

using namespace std;
using ll = long long;
int main() {
  int n;
  ll k;
  cin >> n >> k;
  int h[n];
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }

  int lo = 1, hi = 1e9;
  int ans = 0;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    ll count = 0;
    for (int i = 0; i < n; ++i) {
      count += h[i] / mid;
    }
    if (count >= k) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  cout << ans;
}