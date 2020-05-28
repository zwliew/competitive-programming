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

  int h, m;
  cin >> h >> m;
  if (m >= 45) {
    m -= 45;
  } else {
    int carry = 45 - m;
    h = (h + 23) % 24;
    m = 60 - carry;
  }
  cout << h << ' ' << m;
}
