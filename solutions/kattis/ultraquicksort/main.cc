#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
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

ll mergeSort(vector<int> &v, int lo, int hi) {
  if (lo >= hi) {
    return 0;
  }

  int mid = lo + (hi - lo) / 2;
  ll left = mergeSort(v, lo, mid);
  ll right = mergeSort(v, mid + 1, hi);
  vector<int> next;
  int i = lo, j = mid + 1;
  ll ans = left + right;
  while (i <= mid && j <= hi) {
    if (v[i] <= v[j]) {
      next.push_back(v[i]);
      ++i;
    } else {
      next.push_back(v[j]);
      ++j;
      ans += mid - i + 1;  // Add the number of inversions based on the current
                           // length of the left subarray
    }
  }
  while (i <= mid) {
    next.push_back(v[i]);
    ++i;
  }
  while (j <= hi) {
    next.push_back(v[j]);
    ++j;
  }
  copy(next.begin(), next.end(), v.begin() + lo);

  return ans;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Write merge sort and count whenever we need to place the front element from
  // the right subarray before the front element from the left subarray.
  // Essentially, counting inversions in O(1)
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &x : v) cin >> x;
  cout << mergeSort(v, 0, n - 1);
}
