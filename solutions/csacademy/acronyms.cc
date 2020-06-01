#include <cstring>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int freq[26];
  memset(freq, 0, sizeof freq);
  string vs[n];
  for (int i = 0; i < n; ++i) {
    string x;
    cin >> x;
    freq[x.front() - 'a']++;
    vs[i] = x;
  }

  int count = 0;
  for (int i = 0; i < n; ++i) {
    freq[vs[i].front() - 'a']--;

    int cur_freq[26];
    memset(cur_freq, 0, sizeof cur_freq);
    for (char c : vs[i]) {
      cur_freq[c - 'a']++;
    }

    bool ok = true;
    for (int i = 0; i < 26; ++i) {
      if (cur_freq[i] > freq[i]) {
        ok = false;
        break;
      }
    }
    if (ok) ++count;

    freq[vs[i].front() - 'a']++;
  }
  cout << count;
}