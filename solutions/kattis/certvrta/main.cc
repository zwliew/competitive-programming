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

  map<int, int> x, y;
  for (int i = 0; i < 3; ++i) {
    int cx, cy;
    cin >> cx >> cy;
    x[cx]++;
    y[cy]++;
  }
  for (auto &[val, cnt] : x) {
    if (cnt == 1) {
      cout << val << ' ';
    }
  }
  for (auto &[val, cnt] : y) {
    if (cnt == 1) {
      cout << val;
    }
  }
}
