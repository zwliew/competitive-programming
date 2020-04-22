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

  string s;
  cin >> s;
  int c = 0, t = 0, g = 0;
  for (char x : s) {
    if (x == 'C')
      ++c;
    else if (x == 'T')
      ++t;
    else
      ++g;
  }
  cout << t * t + c * c + g * g + min({t, c, g}) * 7;
}
