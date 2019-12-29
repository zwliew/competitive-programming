#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int a, b, c;
  cin >> a >> b;
  int tmin = 41;
  int dmin = 50;
  for (int i = 3; i <= n; ++i) {
    cin >> c;
    if (max(c, a) < tmin) {
      dmin = i - 2;
      tmin = max(c, a);
    }
    a = b;
    b = c;
  }
  cout << dmin << ' ' << tmin;
}