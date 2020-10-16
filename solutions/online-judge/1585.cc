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
  
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int total = 0;
    int cur = 0;
    for (char c : s) {
      if (c == 'O') {
        ++cur;
      } else {
        total += cur * (cur + 1) / 2;
        cur = 0;
      }
    }
    total += cur * (cur + 1) / 2;
    cout << total << "\n";
  }
}
