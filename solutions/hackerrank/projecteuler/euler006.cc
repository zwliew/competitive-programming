#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int t;
  cin >> t;
  while (t--) {
    int64_t n;
    cin >> n;
    int64_t first = n * (n + 1) * (2 * n + 1) / 6;
    int64_t second = n * (n + 1) / 2;
    second *= second;
    cout << abs(first - second) << '\n';
  }
}

