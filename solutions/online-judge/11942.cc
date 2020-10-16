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

  cout << "Lumberjacks:\n";
  int t;
  cin >> t;
  while (t--) {
    vector<int> nums(10);
    for (int i = 0; i < 10; ++i) {
      cin >> nums[i];
    }
    bool dec = true;
    bool inc = true;
    for (int i = 1; i < 10; ++i) {
      dec = dec && nums[i - 1] >= nums[i];
      inc = inc && nums[i - 1] <= nums[i];
    }

    if (dec || inc) {
      cout << "Ordered\n";
    } else {
      cout << "Unordered\n";
    }
  }
}
