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
    int n;
    string s;
    cin >> n >> s;

    int first8 = -1;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '8') {
        first8 = i;
        break;
      }
    }

    if (first8 == -1) {
      cout << "NO\n";
      continue;
    }

    if (s.size() - first8 < 11) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}