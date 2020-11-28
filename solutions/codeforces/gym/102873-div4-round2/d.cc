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

  int64_t a, s;
  cin >> a >> s;
  if (s < a) {
    cout << "NO";
    return 0;
  }
  int64_t b = s - a;
  string bs = to_string(b);
  string as = to_string(a);
  array<int, 10> cnt;
  fill(cnt.begin(), cnt.end(), 0);
  for (char c : as) {
    cnt[c - '0']++;
  }
  for (char c : bs) {
    cnt[c - '0']--;
  }

  for (int i = 0; i < 10; ++i) {
    if (cnt[i]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}
