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
  int cur = s.size();
  int curmin = 0;
  for (int i = s.size() - 1; i >= 0; --i) {
    if (s[i] != 'A' && s[i] != 'E' && s[i] != 'O' && s[i] != 'U' &&
        s[i] != 'Y' && s[i] != 'I')
      continue;

    curmin = max(curmin, cur - i);
    cur = i;
  }
  cout << max(curmin, cur + 1);
}