#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    //思路:先找到最大的,通过交换使c最大
    if (a > c)
        a ^= c ^= a ^= c;
    if (b > c)
        b ^= c ^= b ^= c;
    //接下来比较剩下两个,使得a<b
    if (b < a)
        a ^= b ^= a ^= b;
    cout << a << "->" << b << "->" << c;
    return 0;
}