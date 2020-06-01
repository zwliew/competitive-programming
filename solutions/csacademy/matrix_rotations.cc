#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> grid[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int c = grid[i][j];

      int ni = n - 1 - j;
      int nj = i;
      c |= grid[ni][nj];

      ni = n - 1 - i;
      nj = n - 1 - j;
      c |= grid[ni][nj];

      nj = n - 1 - i;
      ni = j;
      c |= grid[ni][nj];

      cout << c << ' ';
    }
    cout << '\n';
  }
}