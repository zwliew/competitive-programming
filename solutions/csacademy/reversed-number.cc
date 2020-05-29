#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int x;
  cin >> x;
  string s = to_string(x);
  reverse(s.begin(), s.end());
  int rev = stoi(s);
  cout << (x < rev ? 1 : 0);
}