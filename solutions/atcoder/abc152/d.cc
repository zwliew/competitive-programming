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

typedef long long ll;
typedef long double ld;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  map<pair<int, int>, int> m;
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    int first = 0;
    int j = i;
    while (j) {
      first = j % 10;
      j /= 10;
    }
    auto p = make_pair(first, i % 10);
    if (m.find(p) == m.end()) {
      m[p] = 1;
    } else {
      ++m[p];
    }
  }

  for (int i = 1; i <= n; ++i) {
    int first = 0;
    int j = i;
    while (j) {
      first = j % 10;
      j /= 10;
    }
    auto p = make_pair(i % 10, first);
    cnt += m[p];
  }
  cout << cnt;
}
