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

  int k;
  cin >> k;
  string s;
  cin >> s;

  vector<int> v(26, -1);
  for (char c : s) {
    if (v[c - 'a'] == -1) {
      v[c - 'a'] = 0;
    }
    v[c - 'a']++;
  }

  for (int i : v) {
    if (i == -1) continue;
    if (i % k) {
      cout << -1;
      return 0;
    }
  }

  string ret;
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] == -1) {
      continue;
    }
    for (int j = 0; j < v[i] / k; ++j) {
      ret += i + 'a';
    }
  }

  for (int i = 0; i < k; ++i) {
    cout << ret;
  }
}