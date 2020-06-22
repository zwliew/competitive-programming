#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = -1;
    for (int b = 2; b * 3 < n; ++b) {
      int c = n * n - 2 * n * b + 2 * b * b;
      int denom = n * 2 - 2 * b;
      if (c % denom) continue;
      c /= denom;
      int a = n - b - c;
      ans = max(ans, a * b * c);
    }
    cout << ans << '\n';
  }
}

