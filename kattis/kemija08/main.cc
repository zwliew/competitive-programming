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

  unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  string s;
  while (cin >> s) {
    string ans;
    for (int i = 0; i < s.size(); ++i) {
      ans += s[i];
      if (vowels.count(s[i])) {
        i += 2;
      }
    }
    cout << ans << ' ';
  }
}
