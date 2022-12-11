#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int GPLT[4];

int main() {
    memset(GPLT, 0, sizeof GPLT);
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'G' || s[i] == 'g') GPLT[0]++;
        if (s[i] == 'P' || s[i] == 'p') GPLT[1]++;
        if (s[i] == 'L' || s[i] == 'l') GPLT[2]++;
        if (s[i] == 'T' || s[i] == 't') GPLT[3]++;
    }

    while (1) {
        if (GPLT[0]) {
            cout << 'G';
            GPLT[0]--;
        }
        if (GPLT[1]) {
            cout << 'P';
            GPLT[1]--;
        }
        if (GPLT[2]) {
            cout << 'L';
            GPLT[2]--;
        }
        if (GPLT[3]) {
            cout << 'T';
            GPLT[3]--;
        }
        if (!(GPLT[0] || GPLT[1] || GPLT[2] || GPLT[3])) break;
    }
    return 0;
}