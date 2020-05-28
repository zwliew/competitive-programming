#include <algorithm>
#include <array>
#include <bitset>
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

  int n, m;
  cin >> n >> m;
  int cnt = 0;
  for (int i = 0; i < n + m; ++i) {
    for (int j = 0; j < n + m; ++j) {
      if (i == j) continue;
      if ((i < n && j < n) || (i >= n && j >= n)) {
        ++cnt;
      }
    }
  }
  cout << cnt / 2;
}