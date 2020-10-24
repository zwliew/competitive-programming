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
#include <iterator>
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

  int n, b;
  cin >> n >> b;
  array<unordered_map<int, int>, 2> balances;
  balances[0][0] = 1;
  int curBalance = 0, ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x > b) {
      curBalance++;
    } else if (x < b) {
      curBalance--;
    }
    ans += balances[i % 2][curBalance];
    balances[i % 2 == 0][curBalance]++;
  }
  cout << ans;
}
