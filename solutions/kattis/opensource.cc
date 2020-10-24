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
#include <iterator>
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

  auto islower = [](string& s) {
    for (char c : s) {
      if (isupper(c))
        return false;
    }
    return true;
  };

  string project;
  while (getline(cin, project) && project != "0") {
    unordered_map<string, unordered_set<string>> signedUpFor;
    unordered_map<string, int> cnt;
    string userid;
    while (getline(cin, userid) && userid != "1") {
      if (!islower(userid)) {
        project = userid;
        cnt[project] = 0;
      } else {
        signedUpFor[userid].insert(project);
      }
    }
    for (auto& [k, v] : signedUpFor) {
      if (v.size() == 1) {
        cnt[*v.begin()]++;
      }
    }
    vector<pair<int, string>> projects;
    for (auto& [k, v] : cnt) {
      projects.emplace_back(-v, k);
    }
    sort(projects.begin(), projects.end());
    for (auto& p : projects) {
      cout << p.second << " " << -p.first << "\n";
    }
  }
}
