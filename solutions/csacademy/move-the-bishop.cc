#include <iostream>

using namespace std;

int main() {
  int r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;
  int dr = abs(r1 - r2);
  int dc = abs(c1 - c2);
  if (dr == 0 && dc == 0) {
    cout << 0;
  } else if (dr % 2 != dc % 2) {
    cout << -1;
  } else {
    cout << (dr == dc ? 1 : 2);
  }
}