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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<vector<int>> mat(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    mat[i][0] = 1;
    mat[0][i] = 1;
  }

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
    }
  }
  cout << mat.back().back();
}