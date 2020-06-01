#include <cstring>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int freq[26];
  memset(freq, 0, sizeof freq);
  for (char c : s) {
    freq[c - 'a']++;
  }

  for (char c : s) {
    if (freq[c - 'a'] == 1) {
      cout << c;
      return 0;
    }
  }
  cout << -1;
}