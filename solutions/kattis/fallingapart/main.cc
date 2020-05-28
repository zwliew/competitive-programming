#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Continuously take the next largest value
  int n;
  cin >> n;
  vector<int> vals(n);
  for (int &x : vals) cin >> x;
  sort(vals.rbegin(), vals.rend());
  int a = 0, b = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      a += vals[i];
    } else {
      b += vals[i];
    }
  }
  cout << a << ' ' << b;
}
