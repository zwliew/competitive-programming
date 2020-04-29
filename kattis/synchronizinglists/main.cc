#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
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

  // Sort the arrays and map their corresponding positions
  // Alternatively, sort and binary search for the positions
  int n;
  while (cin >> n && n) {
    vector<int> first(n), second(n);
    for (int &x : first) cin >> x;
    for (int &x : second) cin >> x;

    vector<int> fcopy(n);
    copy(first.begin(), first.end(), fcopy.begin());
    sort(fcopy.begin(), fcopy.end());
    sort(second.begin(), second.end());

    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) {
      m[fcopy[i]] = second[i];
    }

    for (int x : first) {
      cout << m[x] << '\n';
    }
    cout << '\n';
  }
}
