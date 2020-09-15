#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// #include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "cowjog"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int q;
  cin >> q;
  deque<int> front, back;
  while (q--) {
    int cmd, x;
    cin >> cmd;
    if (cmd == 1) {
      cin >> x;
      back.push_back(x);
      if (back.size() > front.size()) {
        front.push_back(back.front());
        back.pop_front();
      }
    } else {
      swap(front, back);
      while (back.size() > front.size()) {
        front.push_back(back.front());
        back.pop_front();
      }
    }
  }

  while (front.size()) {
    cout << front.front() << ' ';
    front.pop_front();
  }
  while (back.size()) {
    cout << back.front() << ' ';
    back.pop_front();
  }
}
