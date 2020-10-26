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

  int n;
  cin >> n;
  vector<int> v(n);
  priority_queue<int> leaves;
  unordered_map<int, int> cnt;
  for (auto& x : v) {
    cin >> x;
    cnt[x]++;
  }

  for (int i = 1; i <= n; ++i) {
    if (!cnt[i]) {
      leaves.push(-i);
    }
  }

  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (leaves.empty()) {
      cout << "Error";
      return 0;
    }
    ans.push_back(-leaves.top());
    leaves.pop();
    cnt[v[i]]--;
    if (!cnt[v[i]]) {
      leaves.push(-v[i]);
    }
  }

  for (int x : ans)
    cout << x << "\n";
}
