#include <stdio.h>

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

  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ++ti) {
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    int rows = 0, cols = 0;
    int trace = 0;
    for (int i = 0; i < n; ++i) {
      vector<bool> row(n);
      for (int j = 0; j < n; ++j) {
        cin >> m[i][j];
        if (i == j) {
          trace += m[i][j];
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      vector<bool> row(n);
      for (int j = 0; j < n; ++j) {
        if (row[m[i][j]]) {
          ++rows;
          break;
        }
        row[m[i][j]] = 1;
      }
    }

    for (int j = 0; j < n; ++j) {
      vector<bool> col(n);
      for (int i = 0; i < n; ++i) {
        if (col[m[i][j]]) {
          ++cols;
          break;
        }
        col[m[i][j]] = 1;
      }
    }

    cout << "Case #" << ti << ": " << trace << ' ' << rows << ' ' << cols
         << '\n';
  }
}
