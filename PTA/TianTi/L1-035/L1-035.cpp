#include "iostream"

using namespace std;

int main() {
    string P[2] = {"", ""};
    int cnt = 0;
    string s;
    while (cin >> s) {
        if (s == ".")
            break;
        cnt++;
        if (cnt == 2)
            P[0] = s;
        if (cnt == 14)
            P[1] = s;
    }

    if (P[0] == "") {
        cout << "Momo... No one is for you ...";
    } else {
        if (P[1] == "") {
            cout << P[0] << " is the only one for you...";
        } else {
            cout << P[0] << " and " << P[1] << " are inviting you to dinner...";
        }
    }
    return 0;
}