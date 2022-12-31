#include "iostream"
#include <memory>

using namespace std;

int main() {
    int K;
    cin >> K;
    K++;
    int cnt = 0;
    string s;
    while (1) {
        cin >> s;
        switch (s[0]) {
        case 'C':
            cnt++;
            if (cnt % K) {
                cout << "Bu"
                     << "\n";
            } else {
                cout << "ChuiZi\n";
            }
            break;
        case 'J':
            cnt++;
            if (cnt % K) {
                cout << "ChuiZi\n";
            } else {
                cout << "JianDao\n";
            }
            break;
        case 'B':
            cnt++;
            if (cnt % K) {
                cout << "JianDao\n";
            } else {
                cout << "Bu\n";
            }
            break;
        default:
            return 0;
        }
    }
    return 0;
}