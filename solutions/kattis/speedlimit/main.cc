#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, a, b, c, t;
  while (cin >> n && n != -1) {
    t = b = 0;
    while (n--) {
      cin >> a >> c;
      t += a * (c - b);
      b = c;
    }
    cout << t << " miles\n";
  }
}