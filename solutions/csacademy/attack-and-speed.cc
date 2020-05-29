#include <iostream>

using namespace std;

int main() {
    int a, ac, k, s, sc;
    cin >> a >> s >> k >> ac >> sc;
    bool swapped = false;
    if (s < a) {
        swap(a, s);
        swap(ac, sc);
        swapped = true;
    }
    
    int lo = 0;
    int hi = k;
    int ans = k;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        long long na = a + mid * ac;
        long long ns = s + (k - mid) * sc;
        if (na <= ns) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    long long na = a + ans * ac;
    long long ns = s + (k - ans) * sc;
    if (na != ns) {
        cout << -1;
    } else {
        if (swapped) {
            cout << k - ans;
        } else {
            cout << ans;
        }
    }
}