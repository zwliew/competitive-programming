#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> rem(3);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        rem[x % 3]++;
    }

    cout << (long long) rem[0] * (rem[0] - 1) / 2 + (long long) rem[1] * rem[2]; 
}