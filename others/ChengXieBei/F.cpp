#include <cmath>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    // cout<<(log2(n)+0.5);
    double a = log2(n);
    int tmp = (int)a;
    if (a - tmp > 0 && m >= tmp + 1) {
        cout << "yes";
    } else if (a == tmp && m >= tmp) {
        cout << "yes";
    } else {
        cout << "no";
    }

    return 0;
}
