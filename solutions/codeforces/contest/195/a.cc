#include <algorithm>
#include <array>
#include <bitset>
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

typedef long long ll;
typedef long double ld;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int a, b, c;
  cin >> a >> b >> c;

  // Better solution
  cout << (-c * (b - a) + b - 1) / b;

  // Binary search solution
  // int lo = 0, hi = c * a / b;
  // int ans = 1e9;
  // while (lo <= hi) {
  //   int mid = lo + (hi - lo) / 2;
  //   if (c + mid > mid * a / (a - b)) {
  //     lo = mid + 1;
  //   } else {
  //     ans = mid;
  //     hi = mid - 1;
  //   }
  // }
  // cout << ans;
}