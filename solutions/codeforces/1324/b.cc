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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    bool f = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 2; j < n; ++j) {
        if (v[i] == v[j]) {
          f = 1;
          break;
        }
      }
      if (f) break;
    }

    if (f) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}