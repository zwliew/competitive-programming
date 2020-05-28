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

  int cur = -1, cursum = 0;
  for (int i = 1; i <= 5; ++i) {
    int sum = 0;
    for (int j = 0; j < 4; ++j) {
      int x;
      cin >> x;
      sum += x;
    }
    if (sum > cursum) {
      cur = i;
      cursum = sum;
    }
  }
  cout << cur << ' ' << cursum;
}
