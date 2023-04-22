#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == a * b)
            cout << "Lv Yan\n";
        else if (c == a + b)
            cout << "Tu Dou\n";
        else
            cout << "zhe du shi sha ya!\n";
    }

    return 0;
}
