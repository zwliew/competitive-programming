#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int best = 0;
  int cur_inc = 0;
  int cur_dec = 0;
  int prev_inc = 0;
  int prev_dec = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x < prev_inc) {
      cur_inc = 0;
    }
    if (x > prev_dec) {
      cur_dec = 0;
    }
    cur_inc++;
    prev_inc = x;
    cur_dec++;
    prev_dec = x;
    best = max({best, cur_inc, cur_dec});
  }

  cout << best;
}