#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
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

using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  bool f = 0;
  for (int i = 1; i <= 5; ++i) {
    string s;
    cin >> s;
    if (s.find("FBI") != s.npos) {
      cout << i << ' ';
      f = 1;
    }
  }
  if (!f) {
    cout << "HE GOT AWAY!";
  }
}
