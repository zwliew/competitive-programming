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

  int n;
  cin >> n;

  int cnt = 0;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i]) {
      a[i] = -1;
      ++cnt;
    } else {
      a[i] = 1;
    }
  }

  int res = -1e9;
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    cur = max(0, cur) + a[i];
    res = max(cur, res);
  }
  cout << res + cnt;
}