#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    --n;
    int64_t num3 = n / 3;
    int64_t num5 = n / 5;
    int64_t num15 = n / 15;
    cout << num3 * (num3 + 1) / 2 * 3 - num15 * (num15 + 1) / 2 * 15 + num5 * (num5 + 1) / 2 * 5 << '\n';
  }
}

