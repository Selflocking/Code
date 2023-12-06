#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fstream in;
    in.open("input.txt");
    if (!in.is_open()) {
        cerr << "Failed to open file" << endl;
        exit(-1);
    }

    int ans = 0;
    while (!in.eof()) {
        string s;
        in >> s;

        int first = -1;
        int last = -1;
        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                if (first == -1) {
                    first = c - '0';
                }
                last = c - '0';
            }
        }

        if (first == -1 || last == -1) {
            cout << "error";
        }

        ans += first * 10 + last;
    }
    cout << ans << endl;
    return 0;
}
