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
  stack<string> events;
  unordered_map<string, int> timeline;
  while (n--) {
    char c;
    cin >> c;
    if (c == 'E') {
      string e;
      cin >> e;
      timeline[e] = events.size();
      events.push(e);
    } else if (c == 'D') {
      int r;
      cin >> r;
      while (r--) {
        timeline.erase(events.top());
        events.pop();
      }
    } else {
      int k;
      cin >> k;
      bool ok = true;
      int earliestDeleted = INT_MAX;
      int latestPresent = -1;
      while (k--) {
        string e;
        cin >> e;
        if (e[0] == '!') {
          e = e.substr(1);
          if (timeline.count(e)) {
            earliestDeleted = min(earliestDeleted, timeline[e]);
          }
        } else if (!timeline.count(e)) {
          ok = false;
        } else {
          latestPresent = max(latestPresent, timeline[e]);
        }
      }

      if (ok) {
        if (earliestDeleted == INT_MAX) {
          cout << "Yes\n";
        } else if (earliestDeleted > latestPresent) {
          cout << events.size() - earliestDeleted << " Just a Dream\n";
        } else {
          cout << "Plot Error\n";
        }
      } else {
        cout << "Plot Error\n";
      }
    }
  }
}
