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
  int cmax = 0;
  int prev = 0;
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    if (prev > a) {
      cmax = 0;
    }
    tmax = max(tmax, ++cmax);
    prev = a;
  }
  cout << tmax;
}