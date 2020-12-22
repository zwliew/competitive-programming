#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <ext/numeric>
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
#define FILE "censor"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    // Original solution
    // while (n--) {
    //   int x;
    //   cin >> x;
    //   cout << __gnu_cxx::power(2, (int)log2(x)) << " ";
    // }

    // Editorial solution
    vector<int> a(n);
    array<int64_t, 2> S;
    fill(S.begin(), S.end(), 0);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      S[i % 2] += a[i];
    }
    bool p = S[0] < S[1];
    for (int i = 0; i < n; ++i) {
      if (i % 2 == p) {
        cout << a[i];
      } else {
        cout << 1;
      }
      cout << " ";
    }

    cout << "\n";
  }
}
