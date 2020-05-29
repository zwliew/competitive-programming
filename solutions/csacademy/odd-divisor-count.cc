#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << (int)sqrt(b) - (int)sqrt(a - 1);
}