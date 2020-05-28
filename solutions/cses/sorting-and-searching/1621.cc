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

  // Sorting a static array is faster than repeatedly inserting into a BST.
  // A hashmap TLEs due to specific test cases that cause a large number of
  // collisions.
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v) cin >> i;
  sort(v.begin(), v.end());
  int cnt = 1;
  for (int i = 1; i < n; ++i) {
    if (v[i] == v[i - 1]) {
      continue;
    }
    ++cnt;
  }
  cout << cnt;
}
