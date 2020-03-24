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

  int n;
  cin >> n;
  vector<int> a(n);
  int cmax = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    cmax = max(cmax, a[i]);
  }
  int r = 0;
  for (int x : a) {
    r += cmax - x;
  }
  cout << r;
}