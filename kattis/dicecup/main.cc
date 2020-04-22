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

  int n, m;
  cin >> n >> m;
  vector<int> v(41);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      v[i + j]++;
    }
  }
  int tmax = *max_element(v.begin(), v.end());
  for (int i = 1; i < 41; ++i) {
    if (v[i] == tmax) {
      cout << i << '\n';
    }
  }
}
