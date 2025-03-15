#include <bits/stdc++.h>
#include <cctype>
#include <cstdio>
#include <string>

using namespace std;

/*
5
SF1234567890
EXAB12345678
INABC123446
123456789012
SF12345

Normal
Express
International
E-commerce
Invalid
*/

void sf(string s) {
    if (s.size() != 12) {
        cout << "Invalid\n";
        return;
    }
    for (int i = 2; i < s.size(); ++i) {
        if (!isdigit(s[i])) {
            cout << "Invalid\n";
            return;
        }
    }
    cout << "Normal\n";
}

void ex(string s) {
    if (s.size() != 12) {
        cout << "Invalid\n";
        return;
    }
    if (!isupper(s[2]) || !isupper(s[3])) {
        cout << "Invalid\n";
        return;
    }
    for (int i = 4; i < s.size(); ++i) {
        if (!isdigit(s[i])) {
            cout << "Invalid\n";
            return;
        }
    }
    cout << "Express\n";
}

void in(string s) {
    if (s.size() != 11) {
        cout << "Invalid\n";
        return;
    }
    if (!isupper(s[2]) || !isupper(s[3]) || !isupper(s[4])) {
        cout << "Invalid\n";
        return;
    }
    for (int i = 5; i < s.size(); ++i) {
        if (!isdigit(s[i])) {
            cout << "Invalid\n";
            return;
        }
    }
    if (((s[9] - '0') + (s[10] - '0')) % 2 != 0) {
        cout << "Invalid\n";
        return;
    }
    cout << "International\n";
}

void ec(string s) {
    if (s.size() != 12) {
        cout << "Invalid\n";
        return;
    }
    if (s[0] == '0') {
        cout << "Invalid\n";
        return;
    }
    for (int i = 1; i < s.size(); ++i) {
        if (!isdigit(s[i])) {
            cout << "Invalid\n";
            return;
        }
    }
    cout << "E-commerce\n";
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (s.size() < 11) {
            cout << "Invalid" << "\n";
            continue;
        }
        if (s[0] == 'S' && s[1] == 'F') {
            sf(s);
        } else if (s[0] == 'E' && s[1] == 'X') {
            ex(s);
        } else if (s[0] == 'I' && s[1] == 'N') {
            in(s);
        } else {
            ec(s);
        }
    }
    return 0;
}