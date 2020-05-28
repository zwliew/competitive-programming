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

  int mod = 1e9 + 7;
  int n;
  cin >> n;
  vector<int> ways(n + 1);
  ways[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= min(i, 6); ++j) {
      ways[i] = (ways[i] + ways[i - j]) % mod;
    }
  }
  cout << ways[n];
}
