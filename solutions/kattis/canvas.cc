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
#include <random>
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

  // Huffman coding variation
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    priority_queue<int64_t> q;
    while (n--) {
      int x;
      cin >> x;
      q.push(-x);
    }

    int64_t total = 0;
    while (q.size() > 1) {
      auto a = -q.top();
      q.pop();
      auto b = -q.top();
      q.pop();
      total += a + b;
      q.push(-(a + b));
    }
    cout << total << "\n";
  }
}
