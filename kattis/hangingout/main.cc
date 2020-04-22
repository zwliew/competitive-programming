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

  // Simulate
  int l, x, cur = 0;
  cin >> l >> x;
  int cnt = 0;
  while (x--) {
    string s;
    int a;
    cin >> s >> a;
    if (s == "enter") {
      if (cur + a > l) {
        cnt++;
      } else {
        cur += a;
      }
    } else {
      cur -= a;
    }
  }
  cout << cnt;
}
