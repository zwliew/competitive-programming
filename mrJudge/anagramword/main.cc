#include <bits/stdc++.h>
using namespace std;
int main() {
    string a,b;
    getline(cin, a);
    getline(cin, b);
    unordered_map<char, int> m;
    for (auto c : a) {
      if (!isalpha(c)) continue;
      c = tolower(c);
      auto i = m.find(c);
      if (i != m.end()) {
        m.at(c) = i->second + 1;
      } else {
        m.emplace(c, 1);
      }
    }
    for (auto c : b) {
      if (!isalpha(c)) continue;
      c = tolower(c);
      auto i = m.find(c);
      if (i == m.end() || i->second == 0) {
        cout << "NO";
        return 0;
      } else {
        m.at(c) = i->second - 1;
      }
    }
    for (auto &i : m) {
      if (i.second > 0) {
        cout << "NO";
        return 0;
      }
    }
    cout << "YES";
    return 0;
}