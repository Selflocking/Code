#include <bits/stdc++.h>

using namespace std;

int main() {
    int a = 2022;
    int ans = 0;
    int time = 0;
    while (a) {
        int t = a % 10;
        ans += t * pow(9, time);
        time = time + 1;
        a /= 10;
    }
    cout << ans << "\n";
    return 0;
}
