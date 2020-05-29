#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int start[n], end[n];
  for (int i = 0; i < n; ++i) {
    cin >> start[i] >> end[i];
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    bool ok = false;
    for (int j = 0; j < n; ++j) {
      if (start[i] > start[j] && end[i] < end[j]) {
        ok = true;
        break;
      }
    }
    ans += ok;
  }
  cout << ans;
}