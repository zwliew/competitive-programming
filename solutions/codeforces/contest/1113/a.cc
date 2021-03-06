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

  int n, v;
  cin >> n >> v;
  int curv = 0;
  int cost = 0;
  for (int i = 1; i < n; ++i) {
    if (curv < v && curv < n - i) {
      cost += (min(n - i, v) - curv) * i;
      curv = min(n - i, v);
    }
    curv--;
  }
  cout << cost;
}