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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<char> v;
  bool f = 0;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (s[0] == s[1] && s[0] == 'O' && !f) {
      v.push_back('+');
      v.push_back('+');
      v.push_back(s[3]);
      v.push_back(s[4]);
      f = 1;
    } else if (s[3] == s[4] && s[3] == 'O' && !f) {
      v.push_back(s[0]);
      v.push_back(s[1]);
      v.push_back('+');
      v.push_back('+');
      f = 1;
    } else {
      v.push_back(s[0]);
      v.push_back(s[1]);
      v.push_back(s[3]);
      v.push_back(s[4]);
    }
  }

  if (f) {
    cout << "YES\n";

    for (int i = 0; i < n; ++i) {
      cout << v[i * 4] << v[i * 4 + 1] << '|' << v[i * 4 + 2] << v[i * 4 + 3]
           << '\n';
    }
  } else {
    cout << "NO\n";
  }
}