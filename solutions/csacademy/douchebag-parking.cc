#include <iostream>

using namespace std;

int main() {
  int n, w;
  cin >> n >> w;
  int cur = 0;
  int start = 1;
  for (int i = 1; i <= n; ++i) {
    int f, l;
    cin >> f >> l;
    if (f) {
      cur += l;
      if (cur >= w) {
        cout << start;
        return 0;
      }
    } else {
      cur = 0;
      start = i + 1;
    }
  }
  cout << -1;
}