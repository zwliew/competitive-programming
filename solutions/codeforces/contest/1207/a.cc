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
    int b, p, f, h, c;
    cin >> b >> p >> f >> h >> c;

    b >>= 1;

    if (h > c) {
      swap(h, c);
      swap(p, f);
    }

    int n = min(f, b);
    b -= n;

    cout << n * c + min(b, p) * h << '\n';
  }
}