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

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());

  // int cnt = 1;
  // int mine = a.back(), his = 0;
  // int i = n - 2, j = 0;
  // while (j <= i) {
  //   if (mine <= his) {
  //     ++cnt;
  //     mine += a[i--];
  //   } else {
  //     his += a[j++];
  //   }
  // }
  // if (mine <= his) {
  //   ++cnt;
  // }
  // cout << cnt;

  int half = accumulate(a.begin(), a.end(), 0) / 2 + 1;
  int cnt = 0, cur = 0;
  while (cur < half) {
    cur += a[cnt++];
  }
  cout << cnt;
}