#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, a, b, c;
  cin >> n;
  while (n--) {
    cin >> a >> b >> c;
    int l = max(a, b);
    if (a + b == c || a * b == c || c * a == b || c * b == a || a + c == b ||
        c + b == a) {
      cout << "Possible\n";
    } else {
      cout << "Impossible\n";
    }
  }
}