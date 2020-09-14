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

  // Simply do as told
  int n;
  cin >> n;
  while (n--) {
    string a, b;
    cin >> a >> b;
    string ans;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] != b[i]) {
        ans.push_back('*');
      } else {
        ans.push_back('.');
      }
    }
    cout << a << "\n" << b << "\n" << ans << "\n\n";
  }
}
