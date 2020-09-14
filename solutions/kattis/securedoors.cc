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
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Simulate the process and use a hashset to keep track of people in the
  // building
  int n;
  cin >> n;
  unordered_set<string> entered;
  while (n--) {
    string a, b;
    cin >> a >> b;
    if (a == "entry") {
      cout << b << " entered";
      if (entered.count(b)) {
        cout << " (ANOMALY)";
      }
      cout << "\n";
      entered.emplace(b);
    } else {
      cout << b << " exited";
      if (!entered.count(b)) {
        cout << " (ANOMALY)";
      }
      cout << "\n";
      entered.erase(b);
    }
  }
}
