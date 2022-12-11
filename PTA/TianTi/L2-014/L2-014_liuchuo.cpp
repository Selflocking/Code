#include <iostream>
#include <set>
using namespace std;
set<int> S;
int main() {
    int n;
    cin >> n;
    S.insert(0);
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        if (t < *S.rbegin()) { S.erase(*S.upper_bound(t)); }
        S.insert(t);
    }
    cout << S.size() - 1;
}