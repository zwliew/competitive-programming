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

  vector<int> op = {'+', '-', '/', '*'};
  unordered_map<int, int> p = {
      {'+', 0},
      {'-', 0},
      {'/', 1},
      {'*', 1},
  };

  auto operate = [&](int x, int y, int z) {
    if (z == '*') {
      return x * y;
    }
    if (z == '/') {
      return x / y;
    }
    if (z == '+') {
    debug(x, y, z);
    }
    return x - y;
  };

  const int P = 227;
  auto compute = [&](vector<int>& infix) {
    stack<int> s;
    vector<int> postfix;
    for (int x : infix) {
      if (x % P == 0) {
        x /= P;
        while (s.size() && p[s.top() / P] >= p[x]) {
          postfix.push_back(s.top());
          s.pop();
        }
        s.push(x * P);
      } else {
        postfix.push_back(x);
      }
    }
    while (s.size()) {
      postfix.push_back(s.top());
      s.pop();
    }

    for (int x : postfix) {
      if (x % P == 0) {
        x /= P;
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        s.push(operate(b, a, x));
      } else {
        s.push(x);
      }
    }
    return s.top();
  };

  unordered_map<int, vector<int>> seen;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      for (int k = 0; k < 4; ++k) {
        vector<int> cur = {4, op[i] * P, 4, op[j] * P, 4, op[k] * P, 4};
        int val = compute(cur);
        seen[val] = cur;
      }
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    if (seen.count(x)) {
      auto cur = seen[x];
      for (auto& y : cur) {
        if (y % P == 0) {
          cout << (char)(y / P) << " ";
        } else {
          cout << y << " ";
        }
      }
      cout << " = " << x;
    } else {
      cout << "no solution";
    }
    cout << "\n";
  }
}
