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
  while (t--) {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    string xs;
    cin >> xs;
    int r = 0, p = 0, s = 0;
    for (char x : xs) {
      if (x == 'R') {
        ++r;
      } else if (x == 'P') {
        ++p;
      } else {
        ++s;
      }
    }
    int win = min(a, s) + min(b, r) + min(c, p);
    if (win * 2 < n) {
      cout << "NO\n";
      continue;
    }

    cout << "YES\n";
    string ret;
    for (int i = 0; i < xs.size(); ++i) {
      if (xs[i] == 'R' && b) {
        --b;
        ret += 'P';
      } else if (xs[i] == 'P' && c) {
        --c;
        ret += 'S';
      } else if (xs[i] == 'S' && a) {
        --a;
        ret += 'R';
      } else {
        ret += 'x';
      }
    }
    for (int i = 0; i < xs.size(); ++i) {
      if (ret[i] == 'x') {
        if (a) {
          --a;
          ret[i] = 'R';
        } else if (b) {
          --b;
          ret[i] = 'P';
        } else {
          ret[i] = 'S';
        }
      }
    }
    cout << ret << '\n';
  }
}