#include <iostream>
using namespace std;

int main() {
    string a;
    string b;
    cin >> a >> b;
    const int n = a.size();

    if (n == 1) {
        if (a == b) {
            cout << "0\n";
        } else {
            cout << "1\n";
            cout << "2 1 " << a << "\n";
        }
        return 0;
    }

    int cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == b[i]) {
            cnt++;
        } else {
            break;
        }
    }
    if (cnt == n) {
        cout << "0\n";
        return 0;
    }

    int a_cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] == a[i]) {
            a_cnt++;
        } else {
            break;
        }
    }
    int b_cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (b[i - 1] == b[i]) {
            b_cnt++;
        } else {
            break;
        }
    }
    if (a_cnt > b_cnt) {
        if (a_cnt + cnt == n) {
            // aaaaabbbbb
            // sdsfdbbbbb
            cout << "1\n";
            cout << "2 " << a_cnt << " " << a[0] << "\n";
            return 0;
        }
    } else {
        if (b_cnt + cnt == n) {
            // sdsfdbbbbb
            // aaaaabbbbb
            cout << "1\n";
            cout << "1 " << b_cnt << " " << b[0] << "\n";
            return 0;
        }
    }

    cout << "2\n";
    cout << "1 " << n << " a\n";
    cout << "2 " << n << " a\n";
    return 0;
}
