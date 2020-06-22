#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int64_t n;
    cin >> n;
    int64_t factor = 1;
    for (int64_t d = 2; d * d <= n; ++d) {
      if (n % d == 0) {
        while (n % d == 0) {
          n /= d;
        }
        factor = d;
      }
    }
    if (n > 1) factor = n;
    cout << factor << '\n';
  }
}

