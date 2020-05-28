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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  vector<vector<int>> a(3, vector<int>(3));
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> a[i][j];
    }
  }

  int n;
  cin >> n;
  while (n--) {
    int b;
    cin >> b;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (a[i][j] == b) {
          a[i][j] = 0;
        }
      }
    }
  }

  for (int i = 0; i < 3; ++i) {
    if (!a[i][0] && !a[i][1] && !a[i][2]) {
      cout << "Yes";
      return 0;
    }
    if (!a[0][i] && !a[1][i] && !a[2][i]) {
      cout << "Yes";
      return 0;
    }
  }

  bool can = 1;
  for (int i = 0; i < 3; ++i) {
    if (a[i][i]) {
      can = 0;
      break;
    }
  }
  if (can) {
    cout << "Yes";
    return 0;
  }

  can = 1;
  for (int i = 0; i < 3; ++i) {
    if (a[i][2 - i]) {
      can = 0;
      break;
    }
  }
  if (can) {
    cout << "Yes";
    return 0;
  }

  cout << "No";
}