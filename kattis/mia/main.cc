#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int s0, s1, r0, r1;
  while (cin >> s0 >> s1 >> r0 >> r1 && (s0 || s1 || r0 || r1)) {
    int sm = s0 > s1 ? s0 : s1;
    int so = s0 > s1 ? s1 : s0;
    int rm = r0 > r1 ? r0 : r1;
    int ro = r0 > r1 ? r1 : r0;
    int x = sm * 10 + so;
    int y = rm * 10 + ro;
    bool xh = x == 21;
    bool yh = y == 21;
    if (xh) {
      if (yh) {
        cout << "Tie.\n";
      } else {
        cout << "Player 1 wins.\n";
      }
    } else if (yh) {
      cout << "Player 2 wins.\n";
    } else if (s0 == s1) {
      if (r0 == r1) {
        if (r0 > s0) {
          cout << "Player 2 wins.\n";
        } else if (r0 == s0) {
          cout << "Tie.\n";
        } else {
          cout << "Player 1 wins.\n";
        }
      } else {
        cout << "Player 1 wins.\n";
      }
    } else if (r0 == r1) {
      cout << "Player 2 wins.\n";
    } else if (x > y) {
      cout << "Player 1 wins.\n";
    } else if (x == y) {
      cout << "Tie.\n";
    } else {
      cout << "Player 2 wins.\n";
    }
  }
}