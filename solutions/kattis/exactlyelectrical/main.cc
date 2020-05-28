#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
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

  // Determine if the excess is a multiple of 2
  int a, b, c, d, t;
  cin >> a >> b >> c >> d >> t;
  int dist = abs(c - a) + abs(d - b);
  if (t >= dist && (t - dist) % 2 == 0) {
    cout << "Y";
  } else {
    cout << "N";
  }
}
