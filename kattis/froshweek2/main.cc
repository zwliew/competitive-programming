#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
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

  // Since each interval can only hold at most 1 task, we sort both the
  // intervals and the tasks in ascending order. Then, try to fit the next
  // smallest task into the next smallest interval.
  int n, m;
  cin >> n >> m;
  vector<int> tasks(n), intervals(m);
  for (int &x : tasks) cin >> x;
  for (int &x : intervals) cin >> x;
  sort(tasks.begin(), tasks.end());
  sort(intervals.begin(), intervals.end());
  int i, j;
  for (i = 0, j = 0; i < n && j < m; ++j) {
    if (tasks[i] <= intervals[j]) {
      ++i;
    }
  }
  cout << i;
}
