#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE ""

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N;
  cin >> N;
  unordered_map<string, pair<int, string>> dates;
  for (int i = 0; i < N; ++i) {
    string name, date;
    int rank;
    cin >> name >> rank >> date;
    if (dates.count(date) && dates[date].first > rank) {
      continue;
    }
    dates.erase(date);
    dates[date] = {rank, name};
  }

  vector<string> names;
  for (auto& [k, v] : dates) {
    names.push_back(v.second);
  }
  sort(names.begin(), names.end());

#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE ""

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  int N;
  cin >> N;
  unordered_map<string, pair<int, string>> dates;
  for (int i = 0; i < N; ++i) {
    string name, date;
    int rank;
    cin >> name >> rank >> date;
    if (dates.count(date) && dates[date].first < rank) {
      dates.erase(date);
    }
    dates[date] = {rank, name};
  }

  vector<string> names;
  for (auto& [k, v] : dates) {
    names.push_back(v.second);
  }
  sort(names.begin(), names.end());

  cout << names.size() << "\n";
  for (auto& s : names) {
    cout << s << "\n";
  }
}

  cout << names.size() << "\n";
  for (auto& s : names) {
    cout << s << "\n";
  }
}
