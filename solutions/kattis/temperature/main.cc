#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, y;
  cin >> x >> y;

  if (x == 0 && y == 1) {
    cout << "ALL GOOD";
  } else if (y == 1) {
    cout << "IMPOSSIBLE";
  } else {
    printf("%.6f", x / (1. - y));
  }
}