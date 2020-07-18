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

  int n, d;
  cin >> n >> d;

  string s;
  cin >> s;

  int cur = 0;
  int cnt = 0;
  while (cur < n - 1) {
    int next = cur;
    for (int i = cur + 1; i <= cur + d; ++i) {
      if (s[i] == '1') next = i;
    }
    if (next == cur) {
      cout << -1;
      return 0;
    }
    cur = next;
    ++cnt;
  }
  cout << cnt;
}