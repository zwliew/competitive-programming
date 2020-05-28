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

  // Simply use hash tables to keep track of definitions
  // Annoying part is to parse the equations
  unordered_map<string, int> ht;
  unordered_map<int, string> hn;
  string cmd;
  while (cin >> cmd) {
    if (cmd == "def") {
      string name;
      int val;
      cin >> name >> val;
      if (ht.count(name)) {
        hn.erase(ht[name]);
      }
      ht[name] = val;
      hn[val] = name;
    } else if (cmd == "calc") {
      string a;
      char op = 0, prevOp = '+';
      bool ok = 1;
      int cur = 0;
      while (op != '=' && cin >> a >> op) {
        cout << a << ' ' << op << ' ';
        if (!ok) continue;
        if (!ht.count(a)) {
          ok = 0;
          continue;
        }
        if (prevOp == '+') {
          cur += ht[a];
        } else {
          cur -= ht[a];
        }
        prevOp = op;
      }
      if (!ok || !hn.count(cur)) {
        cout << "unknown";
      } else {
        cout << hn[cur];
      }
      cout << '\n';
    } else {
      ht = unordered_map<string, int>();
      hn = unordered_map<int, string>();
    }
  }
}
