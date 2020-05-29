#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> glasses;
    while (n--) {
        int x;
        cin >> x;
        glasses.push_back(x);
    }
    nth_element(glasses.begin(), glasses.begin() + k - 1, glasses.end());
    
    int tot = accumulate(glasses.begin(), glasses.begin() + k, 0);
    cout << (tot + 99) / 100;
}