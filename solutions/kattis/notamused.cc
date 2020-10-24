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

  string s;
  int day = 1;
  cout << fixed << setprecision(2);
  while (getline(cin, s)) {
    map<string, double> total;
    cout << "DAY " << day << "\n";
    unordered_map<string, int> entered;
    while (getline(cin, s) && s != "CLOSE") {
      istringstream ss(s);
      vector<string> vals;
      while (ss >> s)
        vals.push_back(s);
      if (vals[0] == "ENTER") {
        entered[vals[1]] = stoi(vals[2]);
      } else {
        total[vals[1]] += (double)0.1 * (stoi(vals[2]) - entered[vals[1]]);
      }
    }

    for (auto& [k, v] : total) {
      cout << k << " $" << v << "\n";
    }
    cout << "\n";
    ++day;
  }
}
