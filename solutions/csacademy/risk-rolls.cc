#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> an(25), bn(25);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    an[x]++;
  }
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    bn[x]++;
  }
  
  int alena = 0;
  for (int i = 0; i < min(n, m); ++i) {
    int abest = 0;
    for (int j = 24; j >= 1; --j) {
      if (an[j]) {
        abest = j;
        an[j]--;
        break;
      }
    }
    int bbest = 0;
    for (int j = 24; j >= 1; --j) {
      if (bn[j]) {
        bbest = j;
        bn[j]--;
        break;
      }
    }
    if (abest > bbest) ++alena;
  }
  
  cout << alena << ' ' << min(n, m) - alena;
}