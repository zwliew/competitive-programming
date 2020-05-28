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

  int n, k;
  cin >> n >> k;
  int fh = n, lh = -1;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x > k) {
      if (fh == n) {
        fh = i;
      } else {
        lh = i;
      }
    }
  }

  if (fh == n) {
    cout << n;
  } else if (lh == -1) {
    cout << n - 1;
  } else {
    cout << fh + n - lh - 1;
  }
}