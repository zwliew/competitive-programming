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
    int ti;
    string s;
    cin >> ti >> s;
    cout << ti << " ";

    int num = 0;
    int denom = 0;
    bool isDenom = false;
    for (char c : s) {
      if (c == '/') {
        isDenom = true;
        continue;
      }

      if (isDenom) {
        denom = denom * 10 + c - '0';
      } else {
        num = num * 10 + c - '0';
      }
    }

    stack<bool> moves;
    while (num != denom) {
      moves.push(num > denom);
      if (num > denom) {
        num -= denom;
      } else {
        denom -= num;
      }
    }

    int ans = 1;
    while (moves.size()) {
      ans = ans * 2 + moves.top();
      moves.pop();
    }
    cout << ans << "\n";
  }
}
