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
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int, int>;

#define eb emplace_back

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, t;
  cin >> n >> t;
  string s;
  cin >> s;
  while (t--) {
    string next = "";
    for (int i = 0; i < s.size(); ++i) {
      if (i < s.size() - 1 && s[i] == 'B' && s[i + 1] == 'G') {
        next += 'G';
        next += 'B';
        ++i;
      } else {
        next += s[i];
      }
    }
    s = next;
  }
  cout << s;
}
