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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  const vector<string> names = {"", "single", "double", "triple"};
  int n;
  cin >> n;
  for (int i = 1; i <= 20; ++i) {
    for (int mi = 1; mi <= 3; ++mi) {
      for (int j = 0; j <= 20; ++j) {
        for (int mj = 1; mj <= 3; ++mj) {
          for (int k = 0; k <= 20; ++k) {
            for (int mk = 1; mk <= 3; ++mk) {
              int total = i * mi + j * mj + k * mk;
              if (total == n) {
                cout << names[mi] << ' ' << i << '\n';
                if (j) {
                  cout << names[mj] << ' ' << j << '\n';
                }
                if (k) {
                  cout << names[mk] << ' ' << k << '\n';
                }
                return 0;
              }
            }
          }
        }
      }
    }
  }
  cout << "impossible";
}
