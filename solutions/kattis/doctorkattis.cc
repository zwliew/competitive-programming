/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

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

  int n;
  cin >> n;
  unordered_map<string, pair<int, int>> nameMap;
  set<tuple<int, int, string>, greater<tuple<int, int, string>>> s;
  int order = INT_MAX;
  while (n--) {
    int c;
    string name;
    int infection;
    pair<int, int> prev;
    cin >> c;
    switch (c) {
      case 0:
        cin >> name >> infection;
        nameMap[name] = {infection, order};
        s.emplace(infection, order, name);
        --order;
        break;
      case 1:
        cin >> name >> infection;
        prev = nameMap[name];
        nameMap[name] = {infection + prev.first, prev.second};
        s.erase({prev.first, prev.second, name});
        s.emplace(infection + prev.first, prev.second, name);
        break;
      case 2:
        cin >> name;
        prev = nameMap[name];
        s.erase({prev.first, prev.second, name});
        nameMap.erase(name);
        break;
      case 3:
        if (s.empty()) {
          cout << "The clinic is empty\n";
        } else {
          cout << get<2>(*s.begin()) << '\n';
        }
        break;
    }
  }
}
