#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // n! / S(n) = x
  // ln(n! / S(n)) = ln(x)
  // ln(n!) - ln(S(n)) = ln(x)
  // ln(S(n)) = 0.5 * (ln(2) + ln(pi) + ln(n)) + n * (ln(n) - ln(e))
  // ln(n!) = lgamma(n + 1)
  // Use lgamma function to compute

  cout << fixed << setprecision(8);

  int n;
  while (cin >> n && n) {
    ld stirling =
        0.5 * (logl(2) + logl(3.1415926535897932384626433832795028841971) +
               logl(n)) +
        n * (logl(n) - 1);
    ld gamma = lgamma(n + 1);
    cout << expl(gamma - stirling) << '\n';
  }
}
