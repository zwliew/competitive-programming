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

  int n;
  cin >> n;
  vector<bool> vals(n);
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    vals[i] = c == 'T';
  }

  stack<bool> prev;
  char c;
  while (cin >> c) {
    if (isalpha(c)) {
      prev.push(vals[c - 'A']);
    } else if (c == '*') {
      bool nxt = prev.top();
      prev.pop();
      nxt &= prev.top();
      prev.pop();
      prev.push(nxt);
    } else if (c == '+') {
      bool nxt = prev.top();
      prev.pop();
      nxt |= prev.top();
      prev.pop();
      prev.push(nxt);
    } else {
      bool nxt = !prev.top();
      prev.pop();
      prev.push(nxt);
    }
  }
  cout << (prev.top() ? "T" : "F");
}
