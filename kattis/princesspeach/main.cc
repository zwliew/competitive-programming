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

  // Store in a hashtable
  int n, y;
  cin >> n >> y;
  unordered_set<int> s;
  while (y--) {
    int x;
    cin >> x;
    s.emplace(x);
  }
  for (int i = 0; i < n; ++i) {
    if (!s.count(i)) {
      cout << i << '\n';
    }
  }
  cout << "Mario got " << s.size() << " of the dangerous obstacles.";
}
