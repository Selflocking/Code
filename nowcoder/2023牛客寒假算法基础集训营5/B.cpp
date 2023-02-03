#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "win-win!\n";
    } else {
        cout << "Yaya-win!\n";
    }
    return 0;
}
