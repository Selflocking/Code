#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        double n;
        cin >> n;
        long long a = (int)n;
        double b = n - a;
        long long zhengshu = 0;
        for (int i = 0; i < 31; ++i) {
            zhengshu += (a & 1) * pow(10, i);
            a >>= 1;
        }
        double xiaoshu = 0;
        for (int i = 1; i <= 4; ++i) {
            b *= 2;
            int tmp = (int)b;
            xiaoshu += tmp * pow(10, 4 - i);
            b = b - tmp;
        }
        // double ans = zhengshu + xiaoshu / 10000;
        // double tmp = xiaoshu/10000;
        // xiaoshu/=10;
        char str[6];
        sprintf(str, "%.3lf", xiaoshu / 10000);
        printf("%lld", zhengshu);
        for (int i = 1; i <= 4; ++i) {
            printf("%c", str[i]);
        }
        printf("\n");
    }
    return 0;
}
