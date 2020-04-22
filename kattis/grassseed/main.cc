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

  // Calculate the number of seeds per lawn
  ld c;
  int l;
  cin >> c >> l;
  ld sum = 0;
  while (l--) {
    ld w, li;
    cin >> w >> li;
    sum += li * w * c;
  }
  cout << fixed << setprecision(7) << sum;
}
