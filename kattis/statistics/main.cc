#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int cnt = 1;
  int n;
  while (cin >> n) {
    int g = -1e7, s = 1e7;
    while (n--) {
      int c;
      cin >> c;
      if (c > g) {
        g = c;
      }
      if (c < s) {
        s = c;
      }
    }
    cout << "Case " << cnt++ << ": " << s << ' ' << g << ' ' << g - s << '\n';
  }
}