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

  freopen("word.in", "r", stdin);
  freopen("word.out", "w", stdout);

  int n, k;
  cin >> n >> k;
  int cur = 0;
  while (n--) {
    string s;
    cin >> s;
    if (cur + s.size() > k) {
      cur = 0;
      cout << '\n';
    }
    if (cur) {
      cout << ' ';
    }
    cur += s.size();
    cout << s;
  }
}