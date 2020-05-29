#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        arr[i] = x;
    }
    sort(arr, arr + n);
    int sum = 0;
    for (int i = 0; i < n - 1; i += 2) {
        sum += arr[i + 1] - arr[i];
    }
    cout << sum;
}