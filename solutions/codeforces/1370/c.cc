/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cpp/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

inline bool isPrime(int n) {
  for (int64_t i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    if (n == 1) {
      cout << "FastestFinger";
    } else if (n % 2) {
      cout << "Ashishgup";
    } else if (n == 2) {
      cout << "Ashishgup";
    } else {
      int cnt = 0;
      while (n % 2 == 0) {
        cnt++;
        n >>= 1;
      }
      if (n == 1) {
        if (cnt > 1) {
          cout << "FastestFinger";
        } else {
          cout << "Ashishgup";
        }
      } else {
        if (cnt > 1) {
          cout << "Ashishgup";
        } else {
          if (isPrime(n)) {
            cout << "FastestFinger";
          } else {
            cout << "Ashishgup";
          }
        }
      }
    }
    cout << '\n';
  }
}
