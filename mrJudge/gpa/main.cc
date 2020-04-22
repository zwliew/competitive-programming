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

  vector<int> score = {80, 70, 65, 60, 55, 50, 45, 40, 0};
  vector<ld> gpa = {4.0, 3.6, 3.2, 2.8, 2.4, 2.0, 1.6, 1.2, 0.8};
  int x;
  cin >> x;
  for (int i = 0; i < score.size(); ++i) {
    if (x >= score[i]) {
      cout << fixed << setprecision(1) << gpa[i];
      return 0;
    }
  }
}
