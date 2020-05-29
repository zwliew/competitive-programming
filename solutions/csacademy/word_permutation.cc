#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, int> hm;
    vector<string> perm;
    for (int i = 1; i <= n; ++i) {
        string x;
        cin >> x;
        hm[x] = i;
        perm.push_back(x);
    }
    
    sort(perm.begin(), perm.end());
    for (int i = 0; i < n; ++i) {
        cout << hm[perm[i]] << ' ';
    }
}