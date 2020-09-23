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

  // Classical bracket matching
  int n;
  cin >> n;
  string s;
  getline(cin, s);
  getline(cin, s);

  unordered_map<char, char> pairs = {
      {')', '('},
      {']', '['},
      {'}', '{'},
  };
  stack<char> prev;
  for (int i = 0; i < n; ++i) {
    assert(i < s.size());

    char c = s[i];
    if (c == '(' || c == '[' || c == '{') {
      prev.push(c);
    } else if (c == ']' || c == '}' || c == ')') {
      if (prev.empty() || prev.top() != pairs[c]) {
        cout << c << ' ' << i;
        return 0;
      }
      prev.pop();
    }
  }
  cout << "ok so far";
}
