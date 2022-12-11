#include <cmath>
#include <iostream>
using namespace std;

int isPrime(long long a) {
    //注意1也要判断
    if(a==1) return 0;
    long long i;
    for (i = 2; i <=sqrt(a); ++i) {
        if (a % i == 0) return 0;
    }
    return 1;
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        long long t;
        cin >> t;
        if (isPrime(t))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}