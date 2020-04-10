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

  string x, y;
  cin >> x >> y;
  vector<vector<int>> editDist(x.size() + 1, vector<int>(y.size() + 1));
  for (int i = 1; i <= x.size(); ++i) {
    editDist[i][0] = i;
  }
  for (int i = 1; i <= y.size(); ++i) {
    editDist[0][i] = i;
  }
  for (int i = 1; i <= x.size(); ++i) {
    for (int j = 1; j <= y.size(); ++j) {
      if (x[i - 1] == y[j - 1]) {
        editDist[i][j] = editDist[i - 1][j - 1];
      } else {
        editDist[i][j] = min({editDist[i - 1][j], editDist[i][j - 1],
                              editDist[i - 1][j - 1]}) +
                         1;
      }
    }
  }
  cout << editDist[x.size()][y.size()];
}
