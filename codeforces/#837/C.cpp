#include <bits/stdc++.h>

using namespace std;

const int mxN = sqrt(1e9);
vector<int> primes;
vector<bool> is_prime;

void colPrime() {
    is_prime.resize(mxN + 2, true);

    primes.emplace_back(2);
    for (int i = 3; i <= mxN; i += 2) {
        if (is_prime[i]) {
            primes.emplace_back(i);
            for (int j = i + i; j <= mxN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    set<int> s;
    for (auto &i : nums) { // 10^5
        for (auto &j : primes) {
            if (j * j > i) break;
            if (i % j == 0) {
                if (!s.insert(j).second) {
                    cout << "YES\n";
                    return;
                }
                while (i % j == 0) i /= j;
            }
        }
        if (i > 1) {
            if (!s.insert(i).second) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    colPrime();
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
