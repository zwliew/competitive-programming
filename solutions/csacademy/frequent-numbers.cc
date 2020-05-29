#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> freq(1001);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        freq[x]++;
    }
    
    int ans = 0;
    for (int i = 1; i <= 1000; ++i) {
        if (freq[i] >= k) ++ans;
    }
    cout << ans;
}