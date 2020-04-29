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

  int c;
  cin >> c;
  while (c--) {
    int n;
    cin >> n;
    vector<ld> v(n);
    ld avg = 0;
    for (ld &x : v) {
      cin >> x;
      avg += x;
    }
    avg /= n;
    int cnt = 0;
    for (ld x : v) {
      if (x > avg) {
        ++cnt;
      }
    }
    cout << fixed << setprecision(3) << ((ld)cnt / n * 100) << "%\n";
  }
}
