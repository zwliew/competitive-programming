#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;

  int maxr = 1;
  size_t sz = s.size();
  for (int r = sqrt(sz); r >= 1; --r) {
    if (sz % r == 0) {
      maxr = r;
      break;
    }
  }

  const int maxc = sz / maxr;

  for (int i = 0; i < maxr; ++i) {
    for (int j = 0; j < maxc; ++j) {
      cout << s[j * maxr + i];
    }
  }
}