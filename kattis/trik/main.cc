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

  int cur = 0;
  char c;
  while (cin >> c) {
    if (c == 'A') {
      if (cur == 0) {
        cur = 1;
      } else if (cur == 1) {
        cur = 0;
      }
    } else if (c == 'B') {
      if (cur == 1) {
        cur = 2;
      } else if (cur == 2) {
        cur = 1;
      }
    } else {
      if (cur == 0) {
        cur = 2;
      } else if (cur == 2) {
        cur = 0;
      }
    }
  }
  cout << cur + 1;
}
