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

  // It is optimal to always place the next cube on top of the next grater cube.
  // Use a BST to efficiently search for the next greater cube.
  // Can also use a sorted array and binary search.
  int n;
  cin >> n;

  // BST solution.
  // multiset<int> t;
  // for (int i = 0; i < n; ++i) {
  //   int k;
  //   cin >> k;
  //   auto it = t.upper_bound(k);
  //   if (it != t.end()) {
  //     t.erase(it);
  //   }
  //   t.emplace(k);
  // }
  // cout << t.size();

  // Binary search solution. Slightly faster since we don't maintain a BST.
  vector<int> t;
  while (n--) {
    int k;
    cin >> k;
    auto it = upper_bound(t.begin(), t.end(), k);
    if (it == t.end()) {
      t.push_back(k);
    } else {
      *it = k;
    }
  }
  cout << t.size();
}
