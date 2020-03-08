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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  int cnt = 0;
  while (n--) {
    int cur = 0;
    for (int i = 0; i < 3; ++i) {
      int x;
      cin >> x;
      if (x) ++cur;
    }
    if (cur > 1) {
      cnt++;
    }
  }
  cout << cnt;
}