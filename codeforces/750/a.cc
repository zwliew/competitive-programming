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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  int avail = 240 - k;
  int lo = 0;
  int hi = n;
  int res = 0;
  while (lo <= hi) {
    int mid = lo + ((hi - lo) / 2);
    int ctime = mid * (mid + 1) / 2 * 5;
    if (ctime > avail) {
      hi = mid - 1;
    } else {
      res = mid;
      lo = mid + 1;
    }
  }
  cout << res;

  // int time = 4 * 60 - k;
  // int cnt = 0;
  // for (int i = 1; i <= n; ++i) {
  //   if (time < 5 * i) {
  //     break;
  //   }
  //   time -= 5 * i;
  //   cnt++;
  // }
  // cout << cnt;
}