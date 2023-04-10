#include <iostream>
using namespace std;
const int N = 2e5 + 10;
long long ans;
long long l[N], r[N];
int main() {
    string s;
    cin >> s;
    long long g = 0, h = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'd') {
            l[i] = g;
            h += g;
        } else if (s[i] == 'u') {
            l[i] = h;
            g++;
        }
    }
    g = 0, h = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'd') {
            r[i] = g;
            h += g;
        } else if (s[i] == 'u') {
            r[i] = h;
            g++;
        }
    }
    long long max = 0, j = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'u') ans = l[i] + r[i];
        if (s[i] == 'd') ans = l[i] * r[i];
        if (ans > max) max = ans, j = i;
    }
    if (j >= 0) s[j] = 'a';
    cout << s;
}