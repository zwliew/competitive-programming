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

  string h = "hello";
  int i = 0;
  for (char c : s) {
    if (c == h[i]) {
      ++i;
    }
    if (i == h.size()) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}