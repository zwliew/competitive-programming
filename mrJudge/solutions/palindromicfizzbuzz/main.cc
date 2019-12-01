#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  uint64_t S, E;
  cin >> S >> E;

  for (uint64_t i = S; i <= E; i++) {
    if (i < 10) {
      cout << "Palindrome!\n";
      continue;
    }

    const string s = to_string(i);
    bool palindrome = true;
    for (size_t j = 0; j < s.size() / 2; j++) {
      if (s[j] != s[s.size() - 1 - j]) {
        palindrome = false;
        break;
      }
    }
    if (palindrome) {
      cout << "Palindrome!\n";
    } else {
      cout << i << '\n';
    }
  }
}