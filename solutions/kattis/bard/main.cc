#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
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

  int n, e;
  cin >> n >> e;
  vector<unordered_set<int>> known(n + 1);
  int song = 0;
  while (e--) {
    int k;
    cin >> k;
    vector<int> villagers(k);
    for (int &x : villagers) cin >> x;
    sort(villagers.begin(), villagers.end());
    unordered_set<int> songs;
    if (villagers[0] == 1) {
      songs.emplace(song);
      ++song;
    } else {
      for (int x : villagers) {
        songs.insert(known[x].begin(), known[x].end());
      }
    }
    for (int x : villagers) {
      known[x].insert(songs.begin(), songs.end());
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (known[i].size() == song) {
      cout << i << '\n';
    }
  }
}
