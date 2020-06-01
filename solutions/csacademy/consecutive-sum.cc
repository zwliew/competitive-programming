#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  for (int a = 1; a < n; ++a) {
    int lo = a + 1, hi = n;
    int ans = hi;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if ((long long)(mid - a + 1) * (mid + a) / 2 <= n) {
        ans = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }

    if ((long long)(ans - a + 1) * (ans + a) / 2 == n) {
      cout << a << ' ' << ans;
      return 0;
    }
  }
  cout << -1;
}