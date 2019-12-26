#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int a, b, c, d, t;
  while (cin >> a >> b >> c >> d && (a || b || c || d)) {
    t = 80;
    t += b > a ? a + (40 - b) : a - b;
    t += 40;
    t += c < b ? c + (40 - b) : c - b;
    t += d > c ? c + (40 - d) : c - d;
    cout << t * 9 << '\n';
  }
}