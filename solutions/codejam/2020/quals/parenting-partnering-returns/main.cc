#include <stdio.h>

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

  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ++ti) {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> a(n);
    for (int i = 0; i < n; ++i) {
      int s, e;
      cin >> s >> e;
      a[i] = {s, e, i};
    }

    sort(a.begin(), a.end());
    vector<char> res(n);
    bool f = 1;
    int c = 0, j = 0;
    for (auto ai : a) {
      int s = get<0>(ai);
      int e = get<1>(ai);
      int i = get<2>(ai);
      if (s >= c) {
        res[i] = 'C';
        c = e;
      } else if (s >= j) {
        res[i] = 'J';
        j = e;
      } else {
        f = 0;
        break;
      }
    }

    cout << "Case #" << ti << ": ";
    if (f) {
      for (char c : res) {
        cout << c;
      }
    } else {
      cout << "IMPOSSIBLE";
    }
    cout << '\n';
  }
}
