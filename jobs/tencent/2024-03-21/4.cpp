#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr int mxN = 405;
vector<int> arr(mxN);
vector<vector<int>> ress(mxN);

void init() {
    for (auto &v : ress) {
        v.resize(mxN);
        for (auto &a : v) {
            a = -1;
        }
    }
}

int n, kk;

int dfs(int x, int k) {
    if (k <= 1) {
        int res = 0;
        for (int i = x; i < n; ++i) {
            res ^= arr[i];
        }
        return res;
    }

    int mx = 0;
    int curr = 0;
    for (int i = x + 1; i <= n - k + 1; ++i) {
        curr ^= arr[i - 1];
        int t = 0;
        if (ress[i][k - 1] != -1)
            t = ress[i][k - 1];
        else
            t = dfs(i, k - 1);
        mx = max(mx, t + curr);
    }
    ress[x][k] = max(ress[x][k], mx);
    return ress[x][k];
}

int main() {
    init();
    cin >> n >> kk;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    // if (kk == 1) {
    //     int curr = 0;
    //     for (auto a : arr) {
    //         curr ^= a;
    //     }
    //     cout << curr << "\n";
    //     return 0;
    // }

    cout << dfs(0, kk) << "\n";
    return 0;
}
