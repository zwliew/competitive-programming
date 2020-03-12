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

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int prev = -1;
    int cmax = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'R') {
        cmax = max(cmax, i - prev);
        prev = i;
      }
    }
    cmax = max<int>(cmax, s.size() - prev);
    cout << cmax << '\n';
  }
}