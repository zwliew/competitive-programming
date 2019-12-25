#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  float t = 0;
  while (n--) {
    float a;
    float b;
    cin >> a >> b;
    t += a * b;
  }
  cout << t;
}