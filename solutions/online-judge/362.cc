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

  int target;
  int ti = 1;
  while (cin >> target && target) {
    int thusFar = 0;
    int prev5s = 0;
    int time = 0;
    int x;
    cout << "Output for data set " << ti << ", " << target << " bytes:\n";
    while (thusFar != target) {
      cin >> x;
      ++time;
      thusFar += x;
      prev5s += x;
      if (time % 5 == 0) {
        cout << "   Time remaining: ";
        if (prev5s) {
          cout << (5 * target - 5 * thusFar + prev5s - 1) / prev5s
               << " seconds\n";
        } else {
          cout << "stalled\n";
        }
        prev5s = 0;
      }
    }
    cout << "Total time: " << time << " seconds\n\n";
    ++ti;
  }
}
