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
  vector<int> x(n);
  int maxSum = 0;
  for (int& i : x) {
    cin >> i;
    maxSum += i;
  }
  vector<bitset<100001>> possible(n + 1, bitset<100001>());
  for (int i = 0; i <= n; ++i) {
    possible[i][0] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 100000; ++j) {
      possible[i][j] = possible[i - 1][j];
      if (!possible[i][j] && j >= x[i - 1]) {
        possible[i][j] = possible[i - 1][j - x[i - 1]];
      }
    }
  }
  vector<int> res;
  for (int i = 1; i <= maxSum; ++i) {
    if (possible[n][i]) {
      res.push_back(i);
    }
  }
  cout << res.size() << '\n';
  for (int i : res) {
    cout << i << ' ';
  }
}
