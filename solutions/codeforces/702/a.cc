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
  int tmax = 0;
  int cur = 0;
  int prev = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (a <= prev) {
      cur = 0;
    }
    prev = a;
    tmax = max(tmax, ++cur);
  }
  cout << tmax;
}