#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<vector<int>, int> hm;
    for (int i = 0; i < n; ++i) {
        vector<int> cnt(26);
        string x;
        cin >> x;
        for (char c : x) {
            int ci = c - 'a';
            cnt[ci]++;
        }
        hm[cnt]++;
    }
    
    int best = 0;
    for (auto &[k, v] : hm) {
        best = max(best, v);
    }
    cout << best;
}