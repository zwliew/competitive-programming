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

  unordered_set<char> s;
  string x;
  cin >> x;
  for (char c : x) {
    s.emplace(c);
  }

  cout << (s.size() & 1 ? "IGNORE HIM!" : "CHAT WITH HER!");
}