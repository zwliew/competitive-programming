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

  // Use a BST to store indices of previously seen values.
  // Hashmap TLEs due to collisions.
  int n, x;
  cin >> n >> x;

  map<int, int> hm;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (hm.count(x - a)) {
      cout << hm[x - a] << ' ' << i + 1;
      return 0;
    }
    hm[a] = i + 1;
  }

  // Alternatively, sort the array and use 2 pointers from the left and right of
  // the array.
  // Only works if there are no negative integers.
  //
  // vector<pair<int, int>> a(n);
  // for (int i = 0; i < n; ++i) {
  //   cin >> a[i].first;
  //   a[i].second = i;
  // }
  // sort(a.begin(), a.end());
  // for (int i = 0, j = n - 1; i < j; ++i) {
  //   while (j > i && a[i].first + a[j].first > x)
  //     --j;
  //   if (i < j && a[i].first + a[j].first == x) {
  //     cout << a[i].second + 1 << ' ' << a[j].second + 1 << '\n';
  //     return 0;
  //   }
  // }

  cout << "IMPOSSIBLE";
}
