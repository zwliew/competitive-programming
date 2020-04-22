#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
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

using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, h, w;
  cin >> n >> h >> w;
  vector<int> v(4);
  v[0] = h * w;
  v[1] = (n - h) * w;
  v[2] = (n - h) * (n - w);
  v[3] = h * (n - w);
  sort(v.begin(), v.end());
  cout << v[3] * 4;
}
