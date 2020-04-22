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

  vector<int> factorials = {1, 1, 2, 6, 4};
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n >= 5) {
      cout << 0 << '\n';
    } else {
      cout << factorials[n] << '\n';
    }
  }
}
