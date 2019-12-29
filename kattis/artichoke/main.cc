#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cout.precision(20);
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  double p, a, b, c, d, n;
  cin >> p >> a >> b >> c >> d >> n;

  double prm = 0, dm = 0;
  for (double ni = 1; ni <= n; ++ni) {
    double pr = p * (sin(a * ni + b) + cos(c * ni + d) + 2);
    if (pr > prm) {
      prm = pr;
    } else if (prm > dm + pr) {
      dm = prm - pr;
    }
  }
  cout << dm;
}