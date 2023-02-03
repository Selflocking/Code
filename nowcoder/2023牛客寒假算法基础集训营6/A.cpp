#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a;
    cin >> a;

    if (a <= 7) {
        cout << "very easy"
             << "\n";
    } else if (a <= 233) {
        cout << "easy"
             << "\n";
    } else if (a <= 10032) {
        cout << "medium"
             << "\n";
    } else if (a <= 114514) {
        cout << "hard"
             << "\n";
    } else if (a <= 1919810) {
        cout << "very hard"
             << "\n";
    } else {
        cout << "can not imagine"
             << "\n";
    }
    return 0;
}
