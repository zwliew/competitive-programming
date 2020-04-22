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

  // Use a BST to store indices of previously seen values.
  // Hashmap TLEs due to collisions.
  // Alternatively, sort the array and use 2 pointers from the left and right of
  // the array.
  int n, x;
  cin >> n >> x;
  map<int, int> hm;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (hm.count(x - a)) {
      cout << hm[x - a] << ' ' << i + 1;
      return 0;
    }
    hm[a] = i + 1;
  }
  cout << "IMPOSSIBLE";
}
