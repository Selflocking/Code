#include <bits/stdc++.h>
#include <bits/types/clock_t.h>
#include <cmath>
#include <ctime>

using namespace std;

constexpr int mxN = 1e9;
vector<int> primes;
bool isPrime(int x) {
    if (x < 1) return false;
    int temp = sqrt(x);
    for (int i = 3; i <= temp; i += 2)
        if (x % i == 0) return false;
    return true;
}

int main() {
    // clock_t begin = clock();
    primes.emplace_back(2);
    for (int i = 3; i <= mxN; i += 2) {
        if (isPrime(i)) {
            primes.emplace_back(i);
        }
    }
    // cout<<clock()-begin<<"\n";
    return 0;
}
