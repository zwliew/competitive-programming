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

  int n, k;
  cin >> n >> k;
  stack<int> prev;
  int cur = 0;
  for (int i = 0; i < k; ++i) {
    string s;
    cin >> s;
    if (s == "undo") {
      int x;
      cin >> x;
      while (x--) {
        cur = ((cur + prev.top()) % n + n) % n;
        prev.pop();
      }
    } else {
      int x = stoi(s);
      cur = ((cur + x) % n + n) % n;
      prev.push(-x);
    }
  }
  cout << cur;
}
