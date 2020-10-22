#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int t;
  cin >> t;
  while (t--) {
    string name;
    getline(cin, name);
    getline(cin, name);
    int n;
    string tmp;
    cin >> n >> tmp;
    cout << name << "\n" << n << " " << tmp << "\n";

    array<int, 10> cnt;
    fill(cnt.begin(), cnt.end(), 0);
    int addressCnt = 0;
    while (addressCnt < n) {
      string s;
      cin >> s;
      if (s[0] != '+') {
        int x = stoi(s);
        while (x) {
          cnt[x % 10]++;
          x /= 10;
        }
        ++addressCnt;
      } else {
        int l, r, d;
        cin >> l >> r >> d;
        for (int i = l; i <= r; i += d) {
          int j = i;
          while (j) {
            cnt[j % 10]++;
            j /= 10;
          }
        }
        addressCnt += (r - l) / d + 1;
      }
    }

    for (int i = 0; i < 10; ++i) {
      cout << "Make " << cnt[i] << " digit " << i << "\n";
    }
    int total = accumulate(cnt.begin(), cnt.end(), 0);
    cout << "In total " << total << " digit" << (total > 1 ? "s" : "") << "\n";
  }
}
