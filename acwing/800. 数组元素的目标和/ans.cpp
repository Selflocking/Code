#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e5 + 5;

int A[mxN];
int B[mxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < m; ++i) cin >> B[i];

    int i = 0;
    int j = m - 1;
    while (1) {
        if (A[i] + B[j] > x) {
            j--;
        } else if (A[i] + B[j] < x) {
            i++;
        } else {
            break;
        }
    }
    // 等价于
    // for (i = 0; i < n; i++) {
    //     while (j >= 0 && A[i] + B[j] > x) j--;
    //     if(A[i]+B[j]==x) break;
    // }

    cout << i << " " << j << "\n";
    return 0;
}