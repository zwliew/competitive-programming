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

  // Sort the array, and determine if it is possible to move every element from
  // the original array to its correct position in the sorted array.
  // Time complexity: O(N^2), dominated by the double nested for-loops
  // int t;
  // cin >> t;
  // while (t--) {
  //   int n, m;
  //   cin >> n >> m;
  //   vector<int> a(n);
  //   vector<bool> p(n);
  //   for (int &i : a) cin >> i;
  //   for (int i = 0; i < m; ++i) {
  //     int x;
  //     cin >> x;
  //     p[x - 1] = 1;
  //   }
  //   vector<pair<int, int>> sorted;
  //   for (int i = 0; i < n; ++i) {
  //     sorted.emplace_back(a[i], i);
  //   }
  //   stable_sort(sorted.begin(), sorted.end());

  //   bool ok = 1;
  //   for (int i = 0; i < n; ++i) {
  //     // Find the correct position of the element in the sorted array.
  //     int dest;
  //     for (int j = 0; j < n; ++j) {
  //       if (sorted[j].second == i) {
  //         dest = j;
  //         break;
  //       }
  //     }

  //     // Determine if it is possible to move the element to the correct
  //     // position.
  //     for (int cur = i; cur < dest; ++cur) {
  //       if (!p[cur]) {
  //         ok = 0;
  //         break;
  //       }
  //     }
  //     for (int cur = i - 1; cur >= dest; --cur) {
  //       if (!p[cur]) {
  //         ok = 0;
  //         break;
  //       }
  //     }

  //     if (!ok) {
  //       break;
  //     }
  //   }
  //   if (ok) {
  //     cout << "YES\n";
  //   } else {
  //     cout << "NO\n";
  //   }
  // }

  // Alternative O(N^2) official solution:
  // Simulate the process, swapping every possible inversion.
  // If there are still inversions but no more swaps can be done, the array
  // cannot be sorted.
  // int t;
  // cin >> t;
  // while (t--) {
  //   int n, m;
  //   cin >> n >> m;
  //   vector<int> a(n);
  //   for (int &i : a) cin >> i;
  //   vector<bool> p(n);
  //   for (int i = 0; i < m; ++i) {
  //     int x;
  //     cin >> x;
  //     p[x - 1] = 1;
  //   }

  //   while (1) {
  //     bool ok = 0;
  //     for (int i = 0; i < n - 1; ++i) {
  //       if (a[i] > a[i + 1] && p[i]) {
  //         ok = 1;
  //         swap(a[i], a[i + 1]);
  //       }
  //     }
  //     if (!ok) break;
  //   }

  //   bool ok = 1;
  //   for (int i = 0; i < n - 1; ++i) {
  //     if (a[i] > a[i + 1]) {
  //       ok = 0;
  //       break;
  //     }
  //   }

  //   if (ok) {
  //     cout << "YES\n";
  //   } else {
  //     cout << "NO\n";
  //   }
  // }

  // Alternative O(NlogN) solution: sort every segment of connected indices, and
  // determine if the entire array is sorted in the end.
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<bool> p(n);
    for (int &i : a) cin >> i;
    for (int i = 0; i < m; ++i) {
      int x;
      cin >> x;
      p[x - 1] = 1;
    }

    for (int i = 0; i < n; ++i) {
      if (!p[i]) continue;
      int j = i;
      while (j < n && p[j]) ++j;
      sort(a.begin() + i, a.begin() + j + 1);
      i = j;
    }

    bool ok = 1;
    for (int i = 0; i < n - 1; ++i) {
      if (a[i] > a[i + 1]) {
        ok = 0;
        break;
      }
    }

    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
