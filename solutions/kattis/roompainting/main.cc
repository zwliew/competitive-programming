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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Binary search for the can size to use
  int n, m;
  cin >> n >> m;
  vector<int> cans(n);
  for (int &x : cans) cin >> x;
  sort(cans.begin(), cans.end());

  ll wasted = 0;
  while (m--) {
    int need;
    cin >> need;
    int actual = *lower_bound(cans.begin(), cans.end(), need);
    wasted += actual - need;
  }

  cout << wasted;
}
