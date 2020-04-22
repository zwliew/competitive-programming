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

  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    int orig = x;
    x /= 1000;
    int a = x * 1000 + 100 * (x % 10) + 10 * ((x / 10) % 10) + (x / 100);
    if (a > orig) {
      --x;
    } else {
      ++x;
    }
    int b = x * 1000 + 100 * (x % 10) + 10 * ((x / 10) % 10) + (x / 100);
    if (a > b) {
      swap(a, b);
    }
    cout << (abs(a - orig) <= abs(b - orig) ? a : b) << '\n';
  }
}
