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

  // Simple arithmetic series math
  int p;
  cin >> p;
  while (p--) {
    int t, n;
    cin >> t >> n;
    cout << t << ' ' << n * (n + 1) / 2 << ' ' << n * n << ' ' << n * (n + 1)
         << '\n';
  }
}
