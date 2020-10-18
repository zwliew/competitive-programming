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

  vector<int> daysInMonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  partial_sum(daysInMonth.begin(), daysInMonth.end(), daysInMonth.begin());

  auto extract = [&](string a, string b, int c) {
    int year = stoi(a.substr(0, 4)) - 2013;
    int month = stoi(a.substr(5, 2)) - 1;
    int day = stoi(a.substr(8)) - 1;
    int hour = stoi(b.substr(0, 2));
    int min = stoi(b.substr(3));
    day += year * 365;
    day += daysInMonth[month];
    if (year == 3 && month >= 2) {
      ++day;
    }
    hour += day * 24;
    min += hour * 60;
    return min + c;
  };

  int t;
  cin >> t;
  while (t--) {
    int b, c;
    cin >> b >> c;
    vector<pair<int, int>> bookings;
    for (int i = 0; i < b; ++i) {
      string x, y;
      cin >> x >> x >> y;
      int s = extract(x, y, 0);
      cin >> x >> y;
      int e = extract(x, y, c);
      bookings.emplace_back(s, 1);
      bookings.emplace_back(e, -1);
      // Alternative solution using a min heap
      // bookings.emplace(s, e);
    }
    sort(bookings.begin(), bookings.end());

    int most = 0;
    int cur = 0;
    for (auto& [x, y] : bookings) {
      cur += y;
      most = max(most, cur);
    }

    // Alternative solution using a min heap
    // priority_queue<int, vector<int>, greater<int>> q;
    // for (auto& [s, e] : bookings) {
    //   while (q.size() && q.top() <= s) {
    //     q.pop();
    //   }
    //   q.push(e);
    //   most = max(most, (int)q.size());
    // }

    cout << most << "\n";
  }
}
