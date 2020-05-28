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

vector<string> mem(10001);
mem[0] =
    "What are you doing at the end of the world? Are you busy? Will you save "
    "us?";
string f(int n) {
  if (!mem[n].empty()) return mem[n];
  string p = f(n - 1);
  return mem[n] = "What are you doing while sending \"" + p +
                  "\"? Are you busy? Will you send \"" + p + "\"?";
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int q;
  cin >> q;
  while (q--) {
    int n, k;
    cin >> n >> k;
    string s = f(n);
    if (k - 1 >= s.size()) {
      cout << '.';
    } else {
      cout << s[k - 1];
    }
  }
}