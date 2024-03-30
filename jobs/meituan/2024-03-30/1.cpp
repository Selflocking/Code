#include <iostream>
using namespace std;

int main() {
    int k, x, y;
    cin >> k >> x >> y;
    // c - a = x
    // b - c = y
    // a + b +c = k;

    // b-a = x+y;
    // 2b+c = k+x+y;
    // 3b = k+x+y+y
    int b = (k + x + y + y) / 3;
    int c = b - y;
    int a = c - x;
    cout << a << " " << b << " " << c << " \n";
    return 0;
}
// 64 位输出请用 printf("%lld")