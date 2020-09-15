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
// #include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "cowjog"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  deque<char> q;
  while (n--) {
    string cmd;
    char x;
    int y;
    cin >> cmd;
    if (cmd == "ADD_BACK") {
      cin >> x;
      q.push_back(x);
    } else if (cmd == "ADD_FRONT") {
      cin >> x;
      q.push_front(x);
    } else if (cmd == "SNIP_BACK") {
      cin >> y;
      while (q.size() > y + 1) {
        q.pop_back();
      }
    } else if (cmd == "SNIP_FRONT") {
      cin >> y;
      for (int i = 0; i <= y; ++i) {
        q.pop_front();
      }
    } else {
      cin >> y;
      cout << q[y] << "\n";
    }
  }
}
