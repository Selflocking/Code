#include <cmath>
#include <iostream>
#include<algorithm>

using namespace std;
//求最大公因数，algorithm头文件中有__gcd()
long gcd(long a, long b) {
    while (b != 0) {
        long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    long a, b;
    int N;
    cin >> N;
    //初始0 0/1
    long fenmu = 1, fenzi = 0, zhengshu = 0;
    while (N--) {
        scanf("%ld/%ld", &a, &b);
        //通分
        fenzi = fenzi * b + fenmu * a;
        fenmu = b * fenmu;
        // 化简,gcd()不能求负数,例如-3 9会输出-3
        long t = gcd(abs(fenzi), fenmu);
        fenzi = fenzi / t;
        fenmu = fenmu / t;
        // 进一步化简，注意要加abs(),例如-9/3
        if (abs(fenzi) >= fenmu) {
            zhengshu += fenzi / fenmu;
            fenzi %= fenmu;
        }
    }
    //输出
    if (zhengshu != 0) {
        if (fenzi != 0) {
            cout << zhengshu << " " << fenzi << "/" << fenmu;
        } else {
            cout << zhengshu;
        }
    } else {
        if (fenzi != 0) {
            cout << fenzi << "/" << fenmu;
        } else {
            cout << 0;
        }
    }
}