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
    int n;
    cin >> n;

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        bestAsk;
    priority_queue<pair<int, int>> bestBid;
    int stock = INT_MIN;
    while (n--) {
      string order, s;
      int x, y;
      cin >> order >> x >> s >> s >> y;
      if (order == "buy") {
        bestBid.emplace(y, x);
      } else {
        bestAsk.emplace(y, x);
      }

      while (bestAsk.size() && bestBid.size() &&
             bestAsk.top().first <= bestBid.top().first) {
        auto [ax, ay] = bestAsk.top();
        auto [bx, by] = bestBid.top();
        bestAsk.pop();
        bestBid.pop();
        stock = ax;
        int sold = min(ay, by);
        ay -= sold;
        by -= sold;
        if (ay) {
          bestAsk.emplace(ax, ay);
        }
        if (by) {
          bestBid.emplace(bx, by);
        }
      }

      if (bestAsk.size()) {
        cout << bestAsk.top().first;
      } else {
        cout << "-";
      }
      cout << " ";
      if (bestBid.size()) {
        cout << bestBid.top().first;
      } else {
        cout << "-";
      }
      cout << " ";
      if (stock != INT_MIN) {
        cout << stock;
      } else {
        cout << "-";
      }
      cout << "\n";
    }
  }
}
