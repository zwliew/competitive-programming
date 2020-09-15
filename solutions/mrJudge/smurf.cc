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
// #include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "cowjog"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  deque<int> smurfs;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (i % 2) {
      smurfs.push_front(x);
    } else {
      smurfs.push_back(x);
    }
  }

  if (n % 2 == 0) {
    for (int i = 0; i < n; ++i) {
      cout << smurfs[i] << " ";
    }
  } else {
    for (int i = n - 1; i >= 0; --i) {
      cout << smurfs[i] << " ";
    }
  }
}
