#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
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

using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Conveniently use the constant-time random access provided by C++ deque
  int n;
  cin >> n;
  deque<int> front, back;
  while (n--) {
    string cmd;
    int x;
    cin >> cmd >> x;
    if (cmd == "push_front") {
      front.push_front(x);
      if (front.size() > back.size() + 1) {
        back.push_front(front.back());
        front.pop_back();
      }
    } else if (cmd == "push_back") {
      back.push_back(x);
      if (back.size() > front.size()) {
        front.push_back(back.front());
        back.pop_front();
      }
    } else if (cmd == "push_middle") {
      if (front.size() == back.size()) {
        front.push_back(x);
      } else {
        back.push_front(x);
      }
    } else {
      if (x >= front.size()) {
        cout << back[x - front.size()];
      } else {
        cout << front[x];
      }
      cout << '\n';
    }
  }
}
