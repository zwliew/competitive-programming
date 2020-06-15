/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 0
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed;

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  int n;
  cin >> n;

  vector<vector<int>> blocks(n);
  for (int i = 0; i < n; ++i) {
    blocks[i].emplace_back(i);
  }

  vector<int> location(n);
  iota(location.begin(), location.end(), 0);

  string a;
  while (cin >> a && a != "quit") {
    int x, y;
    string b;
    cin >> x >> b >> y;

    if (location[x] == location[y]) {
      continue;
    }

    if (b == "onto") {
      while (blocks[location[y]].back() != y) {
        blocks[blocks[location[y]].back()].emplace_back(
            blocks[location[y]].back());
        location[blocks[location[y]].back()] = blocks[location[y]].back();
        blocks[location[y]].pop_back();
      }
    }

    if (a == "move") {
      while (blocks[location[x]].back() != x) {
        blocks[blocks[location[x]].back()].emplace_back(
            blocks[location[x]].back());
        location[blocks[location[x]].back()] = blocks[location[x]].back();
        blocks[location[x]].pop_back();
      }
      blocks[location[x]].pop_back();
      blocks[location[y]].emplace_back(x);
      location[x] = location[y];
    } else {
      vector<int> moving;
      while (blocks[location[x]].back() != x) {
        moving.emplace_back(blocks[location[x]].back());
        location[blocks[location[x]].back()] = location[y];
        blocks[location[x]].pop_back();
      }
      moving.emplace_back(x);
      blocks[location[x]].pop_back();
      location[x] = location[y];
      copy(moving.rbegin(), moving.rend(), back_inserter(blocks[location[y]]));
    }

    debug(blocks);
  }

  for (int i = 0; i < n; ++i) {
    cout << i << ":";
    for (auto x : blocks[i]) {
      cout << ' ' << x;
    }
    cout << '\n';
  }
}
