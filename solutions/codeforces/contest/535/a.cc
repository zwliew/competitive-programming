/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 0
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed;

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  vector<string> words = {
      "zero",     "one",      "two",      "three",   "four",    "five",
      "six",      "seven",    "eight",    "nine",    "ten",     "eleven",
      "twelve",   "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
      "eighteen", "nineteen", "twenty",
  };
  vector<string> tens = {
      "",      "",      "twenty",  "thirty", "forty",
      "fifty", "sixty", "seventy", "eighty", "ninety",
  };

  int n;
  cin >> n;
  if (n <= 20) {
    cout << words[n];
  } else {
    int tensPlace = n / 10;
    int onesPlace = n % 10;
    cout << tens[tensPlace];
    if (onesPlace) {
      cout << '-' << words[onesPlace];
    }
  }
}
