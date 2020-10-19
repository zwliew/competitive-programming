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

  int n;
  cin >> n;
  queue<string> q;
  while (n--) {
    string s;
    cin >> s;
    q.push(s);
  }
  array<deque<pair<string, int>>, 2> teams;
  int time = 0;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      teams[j].emplace_front(q.front(), time++);
      q.pop();
    }
  }

  int record = 0;
  vector<pair<string, string>> holders;
  array<int, 2> cnt = {0, 0};
  auto updateRecord = [&](int idx) {
    if (cnt[idx] > record) {
      record = cnt[idx];
      holders.clear();
    }

    if (cnt[idx] == record) {
      int first = 0;
      int second = 1;
      if (teams[idx][first].second > teams[idx][second].second) {
        swap(first, second);
      }
      holders.emplace_back(teams[idx][first].first, teams[idx][second].first);
    }
  };

  string s;
  cin >> s;
  for (char c : s) {
    bool idx = c != 'W';
    teams[idx].push_back(teams[idx].front());
    teams[idx].pop_front();
    cnt[idx]++;

    updateRecord(!idx);
    q.push(teams[!idx].front().first);
    teams[!idx].pop_front();
    teams[!idx].emplace_back(q.front(), time++);
    q.pop();
    cnt[!idx] = 0;
  }
  updateRecord(0);
  updateRecord(1);
  for (auto& [a, b] : holders) {
    cout << a << " " << b << '\n';
  }
}
