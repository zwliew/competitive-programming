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

  // Use trigonometry to calculate the height of the cannonball
  int t;
  cin >> t;
  while (t--) {
    ld v0, theta, x, h1, h2;
    cin >> v0 >> theta >> x >> h1 >> h2;
    ld dt = x / v0 / cos(theta * 0.01745329251);
    ld y = v0 * dt * sin(theta * 0.01745329251) - dt * dt * 4.905;
    if (y >= h1 + 1 && y <= h2 - 1) {
      cout << "Safe\n";
    } else {
      cout << "Not Safe\n";
    }
  }
}
