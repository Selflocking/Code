#include <bits/stdc++.h>

using namespace std;
constexpr int mxN = 1e9;

vector<int> primes = {2};
vector<bool> isPrime(mxN,true);

int main() {
    for(int i = 3;i<=mxN;++i){
        if(isPrime[i]){
            primes.emplace_back(i);
            for(int j = i+i;j<=mxN;j+=i){
                isPrime[j] = false;
            }
        }
    }
    // cout<<primes.size()<<"\n";
    return 0; 
}
// g++ O2
// 17.922s
