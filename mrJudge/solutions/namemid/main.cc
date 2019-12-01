#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  uint16_t n;
  cin >> s >> n;

  uint16_t pos = 0;
  for (uint16_t i = 0; i < n; i++) {
    cout << string(n - i - 1, ' ');
    for (uint16_t j = 0; j <= i; j++) {
      cout << s[pos] << ' ';
      pos = (pos + 1) % s.size();
    }
    if (i + 1 < n) {
      cout << '\n';
    }
  }
}
