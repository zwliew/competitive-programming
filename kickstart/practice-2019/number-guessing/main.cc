#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  bool tle = false;
  while (t--) {
    int a, b, n;
    cin >> a >> b >> n;
    ++a;
    string s;
    while (b >= a) {
      int m = (a + b) / 2;
      cout << m << endl;
      cin >> s;
      if (s == "CORRECT") {
        break;
      } else if (s == "WRONG_ANSWER") {
        tle = true;
        break;
      } else if (s == "TOO_SMALL") {
        a = m + 1;
      } else if (s == "TOO_BIG") {
        b = m - 1;
      }
    }
    if (tle) {
      break;
    }
  }
}