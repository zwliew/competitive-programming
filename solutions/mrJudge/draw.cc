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
//#include "bits/stdc++.h"

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

  int n, k;
  cin >> n >> k;
  set<pair<int, int>> s;
  unordered_map<int, int> cnt, nums;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    ++cnt[b];
    nums[a] = b;
  }
    
  for (auto& [k, v] : cnt) {
    s.emplace(v, k);
  }

  int ans = s.begin()->first;
  for (int ki = 1; ki < k; ++ki) {
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
      int a, b;
      cin >> a >> b;

      if (nums.find(a) != nums.end()) {
        s.erase({cnt[nums[a]], nums[a]});
        cnt[nums[a]]--;
        if (!cnt[nums[a]]) {
          cnt.erase(nums[a]);
        } else {
          s.emplace(cnt[nums[a]], nums[a]);
        }

        if (!b) {
          nums.erase(a);
        }
      }

      if (b) {
        nums[a] = b;
        s.erase({cnt[b], b});
        cnt[b]++;
        s.emplace(cnt[b], b);
      }
    }
    ans += s.begin()->first;
  }
  cout << ans << "\n";
}
