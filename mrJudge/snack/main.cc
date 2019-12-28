#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  int cursum = 0;
  int maxsum = 0;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    int pt;
    if (isdigit(c)) {
      pt = c - '0';
    } else {
      pt = -2;
    }
    cursum = max(cursum + pt, pt);
    maxsum = max(cursum, maxsum);
  }
  cout << maxsum;
}