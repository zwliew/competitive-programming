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

  string s;
  cin >> s;

  vector<int> prefixSums(s.size() + 1, 0);
  for (int i = 1; i < s.size(); ++i) {
    prefixSums[i] = prefixSums[i - 1] + (s[i] == s[i - 1]);
  }
  prefixSums[s.size()] = prefixSums[s.size() - 1];

  int m;
  cin >> m;
  while (m--) {
    int l, r;
    cin >> l >> r;
    cout << prefixSums[r - 1] - prefixSums[l - 1] << '\n';
  }
}