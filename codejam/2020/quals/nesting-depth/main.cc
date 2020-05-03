#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
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

typedef long long ll;
typedef long double ld;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ++ti) {
    string s;
    cin >> s;
    int cur = 0;
    string res = "";
    for (char c : s) {
      int ci = c - '0';
      if (ci > cur) {
        while (ci > cur) {
          res += '(';
          ++cur;
        }
      } else if (cur > ci) {
        while (cur > ci) {
          res += ')';
          --cur;
        }
      }
      res += c;
    }
    while (cur--) {
      res += ')';
    }
    cout << "Case #" << ti << ": " << res << '\n';
  }
}
