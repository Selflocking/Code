#include <iostream>

using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

bool solve(int a) {
    // 2 3 5 7 11 13 17 19 23
    if (!isPrime(a)) return false;
    if (!isPrime(a + 2)) return false;
    if (!isPrime(a + 4)) return false;
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a;
        cin >> a;
        if (solve(a)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
