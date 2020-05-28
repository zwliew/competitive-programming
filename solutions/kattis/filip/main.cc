#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int a, b;
  cin >> a >> b;
  int c = 0, d = 0;

  while (a > 0) {
    c = c * 10 + (a % 10);
    a /= 10;
  }
  while (b > 0) {
    d = d * 10 + (b % 10);
    b /= 10;
  }
  cout << (c > d ? c : d);
}