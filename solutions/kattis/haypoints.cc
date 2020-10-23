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

  int m, n;
  cin >> m >> n;
  unordered_map<string, int> points;
  while (m--) {
    string s;
    int x;
    cin >> s >> x;
    points[s] = x;
  }

  string s;
  getline(cin, s);
  while (n--) {
    int cur = 0;
    while (getline(cin, s) && s != ".") {
      stringstream ss(s);
      while (ss >> s) {
        cur += points[s];
      }
    }
    cout << cur << "\n";
  }
}
