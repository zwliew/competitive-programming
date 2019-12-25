#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int l, r;
  cin >> l >> r;

  if (l == r && l == 0) {
    cout << "Not a moose";
    return 0;
  }

  if (l == r) {
    cout << "Even " << l * 2;
    return 0;
  }

  int g = l >= r ? l : r;
  cout << "Odd " << g * 2;
}