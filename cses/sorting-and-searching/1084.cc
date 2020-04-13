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

  // Greedily pair the smallest possible apartment with the smallest possible
  // applicant.
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  for (int& i : a) cin >> i;
  for (int& i : b) cin >> i;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int i = 0, j = 0, cnt = 0;
  while (i < n && j < m) {
    if (a[i] - k > b[j]) {
      ++j;
    } else if (a[i] + k < b[j]) {
      ++i;
    } else {
      ++i;
      ++j;
      ++cnt;
    }
  }
  cout << cnt;
}
