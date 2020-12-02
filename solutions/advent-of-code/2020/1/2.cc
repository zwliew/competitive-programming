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

  vector<int> vals;
  int x;
  while (cin >> x) {
    vals.push_back(x);
  }

  unordered_map<int, int> s;
  for (int i = 0; i < vals.size(); ++i) {
    if (s.count(2020 - vals[i])) {
      cout << s[2020 - vals[i]] * vals[i];
      return 0;
    }
    for (int j = 0; j < i; ++j) {
      s[vals[i] + vals[j]] = vals[i] * vals[j];
    }
  }
}
