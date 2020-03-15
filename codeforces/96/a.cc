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

  string a;
  cin >> a;
  // int ct = -1;
  // int ccnt = 0;
  // for (char c : a) {
  //   int t = c - '0';
  //   if (t != ct) {
  //     ccnt = 0;
  //     ct = t;
  //   }
  //   ++ccnt;
  //   if (ccnt == 7) {
  //     cout << "YES";
  //     return 0;
  //   }
  // }
  // cout << "NO";

  if (a.find("0000000") != string::npos || a.find("1111111") != string::npos) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}