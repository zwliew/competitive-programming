#include <iostream>

using namespace std;

int main() {
  int t, c, n;
  cin >> t >> c >> n;
  int x[n], y[n], s[n];
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i] >> s[i];
  }

  for (int i = 0; i < t; ++i) {
    int count = 0;
    for (int j = 0; j < n; ++j) {
      if (1LL * y[j] * c - 1LL * s[j] * c * i == 1LL * s[j] * x[j]) {
        ++count;
      }
    }
    cout << count << '\n';
  }
}