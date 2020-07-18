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

  vector<char> vowel = {'a', 'e', 'i', 'o', 'u', 'y'};
  string ret;
  for (char c : s) {
    bool f = 0;
    for (char v : vowel) {
      if (v == tolower(c)) {
        f = 1;
        break;
      }
    }
    if (f) {
      continue;
    }
    ret += '.';
    ret += tolower(c);
  }

  cout << ret;
}