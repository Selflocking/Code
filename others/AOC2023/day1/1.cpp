#include <bits/stdc++.h>
#include <fstream>

using namespace std;

constexpr int mxN = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fstream in;
    in.open("input.txt");

    long long ans = 0;
    while (!in.eof()) {
        string s;
        in >> s;
        int fist = -1;
        int last = -1;
        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                if (fist == -1) {
                    fist = c - '0';
                }
                last = c - '0';
            }
        }
        if (fist == -1 || last == -1) {
            cout << "error";
        }
        ans += fist * 10 + last;
    }
    cout << ans << endl;
    return 0;
}
