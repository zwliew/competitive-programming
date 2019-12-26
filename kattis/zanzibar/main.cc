#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int a, b, c = 0;
    cin >> a;
    while (cin >> b && b) {
      if (b > a * 2) {
        c += b - a * 2;
      }
      a = b;
    }
    cout << c << '\n';
  }
}