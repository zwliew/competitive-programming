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

  vector<int> v(4);
  cin >> v[0] >> v[1] >> v[2] >> v[3];
  sort(v.begin(), v.end());
  if (v[3] == v[0] + v[1] + v[2] || v[3] + v[0] == v[1] + v[2]) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}