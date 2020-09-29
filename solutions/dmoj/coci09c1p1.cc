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

  int prev;
  cin >> prev;
  bool ascending = true;
  bool descending = true;
  for (int i = 1; i < 8; ++i) {
    int cur;
    cin >> cur;
    ascending = ascending && cur > prev;
    descending = descending && cur < prev;
    prev = cur;
  }

  if (ascending) {
    cout << "ascending";
  } else if (descending) {
    cout << "descending";
  } else {
    cout << "mixed";
  }
}
