#include <iostream>

using namespace std;

int main() {
    int D;
    cin >> D;
    D += 2;
    if (D > 7)
        D -= 7;
    cout << D;
    return 0;
}