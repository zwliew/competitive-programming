#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll gcd(ll a, ll b) {
  ll tmp;
  if (a < b) {
    tmp = a;
    a = b;
    b = tmp;
  }
  while (a != 0) {
    b %= a;
    tmp = b;
    b = a;
    a = tmp;
  }

  return b;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll a, b;
  cin >> a >> b;

  ll g = 1;
  while ((g = gcd(a, b)) > 1) {
    a /= g;
    b /= g;
  }
  cout << a << '/' << b;
}