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

  // Greedily watch as many shows as possible starting from the first show
  int n;
  cin >> n;
  unordered_set<int> a, b;
  vector<int> shows;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a.emplace(x);
    shows.emplace_back(x);
  }
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    b.emplace(x);
    if (!a.count(x)) {
      shows.emplace_back(x);
    }
  }

  sort(shows.begin(), shows.end());
  bool aLiked = 1, bLiked = 1;
  int ans = 0;
  for (int x : shows) {
    bool aLikes = a.count(x);
    bool bLikes = b.count(x);
    if ((aLiked || aLikes) && (bLiked || bLikes)) {
      ++ans;
      aLiked = aLikes;
      bLiked = bLikes;
    }
  }
  cout << ans;
}
