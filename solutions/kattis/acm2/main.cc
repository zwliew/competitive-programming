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

  // Take the p-th task, then greedily take the next task with the lowest cost
  int n, p;
  cin >> n >> p;
  vector<int> tasks(n - 1);
  for (int i = 0; i < p; ++i) {
    cin >> tasks[i];
  }

  int num = 1;
  int time;
  int penalty;
  cin >> time;
  penalty = time;
  if (time > 300) {
    cout << 0 << ' ' << 0;
    return 0;
  }

  for (int i = p; i < n - 1; ++i) {
    cin >> tasks[i];
  }

  sort(tasks.begin(), tasks.end());

  for (int task : tasks) {
    if (time + task <= 300) {
      ++num;
      time += task;
      penalty += time;
    } else {
      break;
    }
  }
  cout << num << ' ' << penalty;
}
