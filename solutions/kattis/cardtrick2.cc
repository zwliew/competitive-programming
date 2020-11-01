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

  vector<vector<int>> ans(14);
  for (int i = 1; i <= 13; ++i) {
    queue<int> q;
    for (int j = 0; j < i; ++j) {
      q.push(j);
    }

    vector<int> cur(i, -1);
    for (int j = 1; j <= i; ++j) {
      for (int k = 0; k < j; ++k) {
        q.push(q.front());
        q.pop();
      }
      cur[q.front()] = j;
      q.pop();
    }
    ans[i] = cur;
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int x : ans[n])
      cout << x << " ";
    cout << "\n";
  }
}
