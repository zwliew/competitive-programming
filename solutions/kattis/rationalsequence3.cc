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
    int ti, idx;
    cin >> ti >> idx;
    cout << ti << " ";

    stack<bool> moves;
    while (idx > 1) {
      moves.push(idx & 1);
      idx >>= 1;
    }

    int num = 1, denom = 1;
    while (moves.size()) {
      if (moves.top()) {
        num += denom;
      } else {
        denom += num;
      }
      moves.pop();
    }
    cout << num << "/" << denom << "\n";
  }
}
