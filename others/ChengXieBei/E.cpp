#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int getNums(int x) {
    int cnt = 0;
    while (x % 2 == 0) {
        x /= 2;
        cnt++;
    }
    int tmp = sqrt(x);
    for (int i = 3; i <= tmp; i += 2) {
        while (x % i == 0) {
            x /= i;
            cnt++;
        }
    }
    if (x != 1) cnt++;
    return cnt;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        int tmp = __gcd(a, b);
        a /= tmp;
        b /= tmp;
        int cnt = getNums(a) + getNums(b) + 2 * getNums(tmp);
        cout << cnt << "\n";
    }
    return 0;
}