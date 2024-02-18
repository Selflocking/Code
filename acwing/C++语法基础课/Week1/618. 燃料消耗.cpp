#include <iostream>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    // 如果 a,b是int, 相乘时也会按照int计算，会爆int
    double l = a * b;
    printf("%.3f\n", l / 12);
    return 0;
}
