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

  ll n;
  cin >> n;
  vector<string> names = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

  ll cur = 1;
  while (n) {
    for (int i = 0; i < names.size(); ++i) {
      n -= cur;
      if (n <= 0) {
        cout << names[i];
        return 0;
      }
    }
    cur <<= 1;
  }
}