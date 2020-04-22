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

  int n;
  cin >> n;
  unordered_map<int, int> m;
  int bestfreq = 0;
  vector<vector<int>> combis(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 5; ++j) {
      int x;
      cin >> x;
      combis[i].push_back(x);
    }
    sort(combis[i].begin(), combis[i].end());
    int hash = 0;
    for (int x : combis[i]) {
      hash = hash * 509 + x;
    }
    m[hash]++;
    if (m[hash] > bestfreq) {
      bestfreq = m[hash];
    }
  }
  int cnt = 0;
  for (auto &[hash, freq] : m) {
    if (freq == bestfreq) {
      cnt += freq;
    }
  }
  cout << cnt;
}
