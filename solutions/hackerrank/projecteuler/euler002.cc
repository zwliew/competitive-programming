#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int64_t n;
    cin >> n;
    int64_t a = 0, b = 2;
    int64_t sum = 0;
    while (b <= n) {
      sum += b;
      a = 4 * b + a;
      swap(a, b);
    }
    cout << sum << '\n';
  }
}

