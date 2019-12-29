#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> m;
        for (auto c : s) {
            auto i = m.find(c);
            if (i == m.end()) {
                m.emplace(c, 1);
            } else {
                m[c] = i->second + 1;
            }
        }
        for (auto c : t) {
            auto i =m.find(c);
            if (i == m.end() || i->second == 0) {
                return false;
            } else {
                m[c] = i->second - 1;
            }
        }
        for (auto i : m) {
            if (i.second > 0) {
                return false;
            }
        }
        return true;
    }
};