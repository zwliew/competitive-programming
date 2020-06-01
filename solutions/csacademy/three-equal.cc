#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int costs[3];
  memset(costs, 0, sizeof costs);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    for (int j = 0; j < 3; ++j) {
      costs[j] += (j - x + 3) % 3;
    }
  }
  cout << min({costs[0], costs[1], costs[2]});
}