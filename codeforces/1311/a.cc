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

  // We only ever need to use at most 2 moves.
  // Maximum of 2 moves is achieved by either adding 1 and subtracting an even
  // number, or adding 1 and adding an odd number.
  // a == 1, b == 5. a + 1 + 3 == b
  // a == 5, b == 2. a - 4 + 1 == b
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (a < b) {
      if ((b - a) & 1) {
        cout << "1\n";
      } else {
        cout << "2\n";
      }
    } else if (a > b) {
      if ((a - b) & 1) {
        cout << "2\n";
      } else {
        cout << "1\n";
      }
    } else {
      cout << "0\n";
    }
  }
}
