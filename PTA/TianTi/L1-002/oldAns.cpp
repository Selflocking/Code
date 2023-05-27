#include <cmath>
#include <iostream>
using namespace std;

int main() {
    double n;
    char ch;
    cin >> n >> ch;
    int count = n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    int t = (int)sqrt((n +1)/ 2 );

    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << " ";
        }
        for (int j = t + t - 1; j > i + i; j--) {
            cout << ch;
            --count;
        }
        cout << endl;
    }

    for (int i = t; i < t + t - 1; ++i) {
        for (int j = t + t - 1; j > i + 1; --j) {
            cout << " ";
        }
        for (int j = 0; j < i + i - t - t + 3; j++) {
            cout << ch;
            --count;
        }
        cout << endl;
    }
    cout <<count;

    return 0;
}
