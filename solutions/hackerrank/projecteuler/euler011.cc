#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> grid(20, vector<int>(20));
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            cin >> grid[i][j];
        }
    }

    int best = 0;
    for (int i = 0; i < 20; ++i) {
        int endi = i + 4;
        for (int j = 0; j < 20; ++j) {
            int endj = j + 4;
            int startj = j - 3;
            int prod = 1;
            if (endj <= 20) {
                prod = 1;
                for (int k = j; k < endj; ++k) {
                    prod *= grid[i][k];
                }
                best = max(best, prod);
            }

            if (endi <= 20) {
                prod = 1;
                for (int k = i; k < endi; ++k) {
                    prod *= grid[k][j];
                }
                best = max(best, prod);
            }

            if (endi <= 20 && endj <= 20) {
                prod = 1;
                for (int k = 0; k < 4; ++k) {
                    prod *= grid[i + k][j + k];
                }
                best = max(best, prod);
            }

            if (endi <= 20 && startj >= 0) {
                prod = 1;
                for (int k = 0; k < 4; ++k) {
                    prod *= grid[i + k][j - k];
                }
                best = max(best, prod);
            }
        }
    }

    cout << best;
}
