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

  string s;
  cin >> s;

  int cnt = 0;
  // for (int i = 0; i < s.size(); ++i) {
  //   for (int j = i + 1; j < s.size(); ++j) {
  //     for (int k = j + 1; k < s.size(); ++k) {
  //       if (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q') {
  //         ++cnt;
  //       }
  //     }
  //   }
  // }

  vector<int> qcnt(s.size(), 0);
  qcnt[0] = s[0] == 'Q';
  for (int i = 1; i < s.size(); ++i) {
    qcnt[i] = qcnt[i - 1] + (s[i] == 'Q');
  }
  for (int i = 1; i < s.size() - 1; ++i) {
    if (s[i] == 'A') {
      cnt += qcnt[i - 1] * (qcnt[s.size() - 1] - qcnt[i - 1]);
    }
  }
  cout << cnt;
}