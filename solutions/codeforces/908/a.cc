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

  string s;
  cin >> s;
  int cnt = 0;
  for (char c : s) {
    if (isdigit(c)) {
      if ((c - '0') % 2 == 1) ++cnt;
    } else {
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ++cnt;
    }
  }
  cout << cnt;
}