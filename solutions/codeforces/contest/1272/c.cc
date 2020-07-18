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

  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<bool> c(26, 0);

  for (int i = 0; i < k; ++i) {
    char x;
    cin >> x;
    c[x - 'a'] = 1;
  }

  ll curcnt = c[s.front() - 'a'];
  ll totcnt = c[s.front() - 'a'];
  for (int i = 1; i < s.size(); ++i) {
    curcnt = c[s[i] - 'a'] * (curcnt + 1);
    totcnt += curcnt;
  }

  cout << totcnt;
}