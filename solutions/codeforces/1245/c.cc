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

  if (s.find('m') != string::npos || s.find('w') != string::npos) {
    cout << 0;
    return 0;
  }

  ll a = 1, b = 1;
  for (int i = 2; i <= s.size(); ++i) {
    ll tmp =
        (b + ((s[i - 1] == s[i - 2] && (s[i - 1] == 'u' || s[i - 1] == 'n'))
                  ? a
                  : 0)) %
        1000000007;
    a = b;
    b = tmp;
  }
  cout << b;
}