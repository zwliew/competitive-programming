#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
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

  char c;
  int totalCnt = 0;
  int whitespace = 0, lowercase = 0, uppercase = 0, symbol = 0;
  while (cin >> c) {
    ++totalCnt;
    if (islower(c)) {
      ++lowercase;
    } else if (isupper(c)) {
      ++uppercase;
    } else if (c == '_') {
      ++whitespace;
    } else {
      ++symbol;
    }
  }
  cout << fixed << setprecision(6);
  cout << (double)whitespace / totalCnt << "\n"
       << (double)lowercase / totalCnt << "\n"
       << (double)uppercase / totalCnt << "\n"
       << (double)symbol / totalCnt << "\n";
}
