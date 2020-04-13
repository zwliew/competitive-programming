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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(n + 1);
    int distinct = 0;
    int maxEqual = 0;
    for (int& i : a) {
      cin >> i;
      if (!cnt[i]) {
        ++distinct;
      }
      ++cnt[i];
      maxEqual = max(maxEqual, cnt[i]);
    }
    if (distinct < maxEqual) {
      cout << (distinct) << '\n';
    } else if (distinct == maxEqual) {
      cout << distinct - 1 << '\n';
    } else {
      cout << maxEqual << '\n';
    }
  }
}
