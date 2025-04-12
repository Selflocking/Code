#include <iostream>
#include <vector>

using namespace std;

int n, m;

int merge(vector<int> &a, vector<int> &b) {
    int res = 1e9 + 10;
    for (int i = 0; i < m; ++i) {
        res = min(res, max(a[i], b[i]));
    }
    return res;
}

int main() {
    cin >> n >> m;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i].resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ans = max(ans, merge(arr[i], arr[j]));
        }
    }
    cout << ans << "\n";
    return 0;
}
