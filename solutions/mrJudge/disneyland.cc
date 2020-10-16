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
  map<int, int> s;
  deque<pair<int, int>> q;
  while (n--) {
    int entry, pi, id;
    cin >> entry;
    if (entry) {
      cin >> pi >> id;
      if (s.empty() || pi > s.rbegin()->first) {
        q.emplace_front(id, pi);
      } else {
        q.emplace_back(id, pi);
      }
      s[pi]++;
    } else {
      if (q.empty()) {
        cout << "-1\n";
        continue;
      }
      auto& [id, pi] = q.front();
      cout << id << "\n";
      if (s[pi] == 1) {
        s.erase(pi);
      } else {
        --s[pi];
      }
      q.pop_front();
    }
  }
}
