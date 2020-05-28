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

  // Take the longest segments
  int n;
  cin >> n;
  for (int ni = 1; ni <= n; ++ni) {
    int s;
    cin >> s;
    vector<int> blue, red;
    for (int i = 0; i < s; ++i) {
      string x;
      cin >> x;
      bool isBlue = x.back() == 'B';
      int num = stoi(x.substr(0, x.size() - 1));
      if (isBlue) {
        blue.push_back(num);
      } else {
        red.push_back(num);
      }
    }

    sort(blue.rbegin(), blue.rend());
    sort(red.rbegin(), red.rend());

    int i = 0, j = 0;
    int ans = 0;
    while (i < blue.size() && j < red.size()) {
      ans += blue[i] + red[j] - 2;
      ++i;
      ++j;
    }

    cout << "Case #" << ni << ": " << ans << '\n';
  }
}
