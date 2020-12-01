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
  
  string s;
  cin >> s;
  istringstream ss(s);
  vector<int> ops;
  while (getline(ss, s, ',')) {
    ops.push_back(stoi(s));
  }
  ops[1] = 12;
  ops[2] = 2;

  for (int i = 0; i < ops.size() && ops[i] != 99;) {
    if (ops[i] == 1) {
      int sum = ops[ops[i + 1]] + ops[ops[i + 2]];
      ops[ops[i + 3]] = sum;
      i += 4;
    } else if (ops[i] == 2) {
      int prod = ops[ops[i + 1]] * ops[ops[i + 2]];
      ops[ops[i + 3]] = prod;
      i += 4;
    }
  }
  cout << ops[0];
}
