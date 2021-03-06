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
  vector<int> h(101, 0), g(101, 0);
  int cnt = 0;
  while (n--) {
    int x, y;
    cin >> x >> y;
    cnt += g[x];
    cnt += h[y];
    h[x]++;
    g[y]++;
  }

  cout << cnt;

  // Alternative brute force solution
  // int n;
  // cin >> n;
  // vii col;
  // for (int i = 0; i < n; ++i) {
  //   int h, g;
  //   cin >> h >> g;
  //   col.emplace_back(h, g);
  // }

  // int ans = 0;
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < n; ++j) {
  //     if (i == j) continue;
  //     if (col[i].first == col[j].second) {
  //       ++ans;
  //     }
  //   }
  // }

  // cout << ans;
}
