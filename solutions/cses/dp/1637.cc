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

typedef long long ll;
typedef long double ld;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  // Greedy algorithm - subtract the largest digit at every step
  // int cnt = 0;
  // while (n) {
  //   int j = n;
  //   int best = 0;
  //   while (j) {
  //     best = max(best, j % 10);
  //     j /= 10;
  //   }
  //   n -= best;
  //   ++cnt;
  // }
  // cout << cnt;

  // DP algorithm - try every single digit and keep the minimum
  vector<int> minSteps(n + 1, 1e9);
  minSteps[0] = 0;
  for (int i = 1; i <= n; ++i) {
    int j = i;
    while (j) {
      minSteps[i] = min(minSteps[i], minSteps[i - j % 10] + 1);
      j /= 10;
    }
  }
  cout << minSteps[n];
}
