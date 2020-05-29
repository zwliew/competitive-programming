#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;
    int total[1001];
    memset(total, 0, 1001 * sizeof(int));
    while (n--) {
        int x;
        cin >> x;
        total[x] += x;
    }
    int best = 0;
    int sum = 0;
    for (int i = 1; i <= 1000; ++i) {
        best = max(best, total[i]);
        sum += total[i];
    }
    cout << sum - best;
}