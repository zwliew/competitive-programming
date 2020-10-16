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
    int p = 0;
    vector<int> prev;
    while (n--) {
      string s;
      cin >> s;
      if (s == "LEFT") {
        prev.push_back(-1);
      } else if (s == "RIGHT") {
        prev.push_back(1);
      } else {
        cin >> s;
        int x;
        cin >> x;
        prev.push_back(prev[x - 1]);
      }
      p += prev.back();
    }
    cout << p << "\n";
  }
}
