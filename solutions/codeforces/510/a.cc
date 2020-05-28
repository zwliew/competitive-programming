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
  bool r = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i % 2 == 0) {
        cout << '#';
      } else if (j == m - 1 && r) {
        cout << '#';
      } else if (j == 0 && !r) {
        cout << '#';
      } else {
        cout << '.';
      }
    }
    if (i % 2) r = !r;
    cout << '\n';
  }
}