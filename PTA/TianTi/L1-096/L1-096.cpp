#include <bits/stdc++.h>
#include <string>

using namespace std;

constexpr int mxN = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int na, nb;
        cin >> na >> nb;

        string a = to_string(na);
        string b = to_string(nb);

        int sa = 0;
        for (auto c : a) sa += c - '0';
        int sb = 0;
        for (auto c : b) sb += c - '0';

        bool A = false;
        bool B = false;
        if (na % sb == 0) A = true;
        if (nb % sa == 0) B = true;

        if ((A && B) || (!A && !B)) {
            cout << (na > nb ? 'A' : 'B') << "\n";
        } else {
            cout << (A ? 'A' : 'B') << "\n";
        }
    }

    return 0;
}
