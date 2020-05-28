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

  // Just multiply the numbers
  int t;
  cin >> t;
  while (t--) {
    vector<vector<int>> v(2);
    for (int i = 0; i < 2; ++i) {
      int n;
      cin >> n;
      for (int j = 0; j <= n; ++j) {
        int a;
        cin >> a;
        v[i].push_back(a);
      }
    }
    vector<int> ans;
    for (int i = 0; i < v[0].size(); ++i) {
      for (int j = 0; j < v[1].size(); ++j) {
        int deg = i + j;
        if (ans.size() <= deg) {
          ans.resize(deg + 1);
        }
        ans[deg] += v[0][i] * v[1][j];
      }
    }

    cout << ans.size() - 1 << '\n';
    for (int i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}
