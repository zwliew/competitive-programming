#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int a[1001];
  int b[1001];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  int ans = 0;
  for (int i = 0; i < m - n + 1; ++i) {
    bool ok = true;
    for (int j = 0; j < n; ++j) {
      if (a[j] + b[i + j] != 1) {
        ok = false;
        break;
      }
    }
    if (ok) ++ans;
  }
  cout << ans;
}