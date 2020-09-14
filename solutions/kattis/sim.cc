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
//#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "perimeter"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Simulate the process using a linked list
  int t;
  cin >> t;
  string s;
  getline(cin, s);
  while (t--) {
    getline(cin, s);

    list<char> l;
    auto cur = l.begin();
    for (char c : s) {
      if (c == '<') {
        if (cur != l.begin()) {
          l.erase(prev(cur));
        }
      } else if (c == '[') {
        cur = l.begin();
      } else if (c == ']') {
        cur = l.end();
      } else {
        l.insert(cur, c);
      }
    }

    for (char c : l) {
      cout << c;
    }
    cout << '\n';
  }
}
