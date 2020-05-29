#include <iostream>

using namespace std;

int main() {
    long long n, m, x , y;
    cin >> n >> m >> x >> y;
    cout << min(n, (m + n * y) / (x + y));
}