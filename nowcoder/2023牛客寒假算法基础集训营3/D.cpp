#include <bits/stdc++.h>

using namespace std;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "kou\n";
    } else {
        cout << "yukari\n";
    }
    return 0;
}
