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

  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  queue<int> q;
  int csum = 0;
  for (int i = 0; i < k; ++i) {
    q.emplace(h[i]);
    csum += h[i];
  }
  int minsum = csum;
  int minidx = 0;
  for (int i = k; i < n; ++i) {
    csum -= q.front();
    q.pop();
    q.emplace(h[i]);
    csum += h[i];
    if (csum < minsum) {
      minsum = csum;
      minidx = i - k + 1;
    }
  }
  cout << minidx + 1;
}