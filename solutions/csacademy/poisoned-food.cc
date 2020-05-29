#include <iostream>

using namespace std;
using ld = long double;
int main() {
  int n;
  cin >> n;
  ld best = -1e9;
  int besti = 0;
  for (int i = 0; i < n; ++i) {
    ld t, p;
    cin >> t >> p;
    ld rat = (t - p) / t;
    if (rat > best) {
      best = rat;
      besti = i;
    }
  }
  cout << besti + 1;
}