#include <cmath>
#include <iostream>

using namespace std;

int max(int a, int b) {
    return (a + b + abs(a - b)) / 2;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int res = max(a, max(b, c));
    cout << res << " eh o maior" << endl;
    return 0;
}
