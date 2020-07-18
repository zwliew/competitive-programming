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

struct Date {
  int year;
  int month;
  int day;

  bool operator!=(const Date& rhs) const {
    return tie(year, month, day) != tie(rhs.year, rhs.month, rhs.day);
  }

  bool operator<(const Date& rhs) const {
    return tie(year, month, day) < tie(rhs.year, rhs.month, rhs.day);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  string start, end;
  cin >> start >> end;
  stringstream ss(start);
  vector<int> tokens;
  while (getline(ss, start, ':')) {
    tokens.emplace_back(stoi(start));
  }
  Date cur = {tokens[0], tokens[1] - 1, tokens[2] - 1};
  ss = stringstream(end);
  tokens.clear();
  while (getline(ss, end, ':')) {
    tokens.emplace_back(stoi(end));
  }
  Date target = {tokens[0], tokens[1] - 1, tokens[2] - 1};

  if (target < cur) {
    swap(target, cur);
  }

  auto isLeap = [](int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100);
  };

  vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int ans = 0;
  while (cur != target) {
    ++ans;
    bool nextMonth = false;
    cur.day++;
    if (cur.month == 1 && isLeap(cur.year)) {
      nextMonth = cur.day == 29;
    } else {
      nextMonth = cur.day == days[cur.month];
    }

    if (nextMonth) {
      cur.day = 0;
      cur.month++;
    }

    if (cur.month == 12) {
      cur.month = 0;
      cur.year++;
    }
  }

  cout << ans;
}
