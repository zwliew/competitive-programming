#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, i, x = 0;
  cin >> n;
  while (n--) {
    cin >> i;
    if (i < 0) x -= i;
  }
  cout << x;
}