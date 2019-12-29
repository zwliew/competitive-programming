#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m;
  char p;
  string s;
  int t = 0, c = 0;
  unordered_map<int, int> k;
  while (cin >> m && m != -1) {
    cin >> p >> s;
    if (s == "right") {
      t += m;
      t += k.find(p) != k.end() ? k[p] * 20 : 0;
      ++c;
    } else {
      if (k.find(p) == k.end()) {
        k[p] = 1;
      } else {
        ++k[p];
      }
    }
  }
  cout << c << ' ' << t;
}