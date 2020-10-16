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

  int n;
  cin >> n;
  vector<bool> cols(n), rows(n), diag1s(n * 2), diag2s(n * 2);
  for (int i = 0; i < n; ++i) {
    int r, c;
    cin >> r >> c;
    if (rows[r] || cols[c] || diag1s[r + c] || diag2s[r - c + n - 1]) {
      cout << "INCORRECT";
      return 0;
    }
    rows[r] = true;
    cols[c] = true;
    diag1s[r + c] = true;
    diag2s[r - c + n - 1] = true;
  }
  cout << "CORRECT";
}
