#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string a, b;
  cin >> a >> b;
  if ((a + a).find(b) != string::npos) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}