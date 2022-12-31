#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;
constexpr int mxN = 1e5 + 5;

string s = "114514";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;
    cout << "3 " << s[x - 1] << "\n";
    return 0;
}
