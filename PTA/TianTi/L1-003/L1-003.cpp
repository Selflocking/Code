#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<char, int> res;
    string s;
    cin >> s;
    for (auto c : s) {
        res[c]++;
    }
    for (auto it : res) {
        cout << it.first << ":" << it.second << "\n";
    }
    return 0;
}
