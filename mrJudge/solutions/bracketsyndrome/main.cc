#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  uint32_t n;
  string s;
  cin >> n >> s;

  if (n == 0) {
    cout << 0;
    return 0;
  }

  uint32_t n_open = 0;
  uint32_t n_pre = 0;
  for (char c : s) {
    if (c == '(') {
      ++n_open;
    } else if (c == ')') {
      if (n_open == 1) {
        ++n_pre;
      } else if (n_open == 0) {
        goto end;
      }
      --n_open;
    }
  }

end:
  cout << n_pre;
}

/*
dp:
for a sequence s with length n,
1. if n == 0, return 0
2. if s is an encompassing sequence, return 1
3. else, return the no. of prefixes for the sequence excluding the suffix sequence + 1
*/