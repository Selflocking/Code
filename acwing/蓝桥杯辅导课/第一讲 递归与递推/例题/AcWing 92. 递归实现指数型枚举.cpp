#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int ed = (1 << n); // 2^(n-1) + 1 即 2^n
    for (int i = 0; i < ed; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                cout << j + 1 << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}