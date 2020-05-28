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

// vector<vector<int>> mem(16, vector<int>(361, -1));

// bool dp(int n, int cur, vector<int> &a) {
//   if (n < 0) {
//     return !cur;
//   }
//   if (mem[n][cur] != -1) {
//     return mem[n][cur];
//   }
//   return mem[n][cur] = dp(n - 1, (cur + a[n]) % 360, a) ||
//                        dp(n - 1, (cur - a[n] + 360) % 360, a);
// }

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  // DP solution: O(n)
  // cout << (dp(n - 1, 0, a) ? "YES" : "NO");

  // Brute force solution: O(pow(2, n) * n)
  for (int i = 0; i < (1 << n); ++i) {
    int deg = 0;
    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) {
        deg += a[j];
      } else {
        deg -= a[j];
      }
    }
    if (!(deg % 360)) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}