#include <iostream>

using namespace std;

int n, m, q;

int arr[1010][1010];
int sum[1010][1010];

int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            sum[i][j] =
                sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
        }
    }
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        // 注意这里，注意边界
        cout << sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1]
             << "\n";
    }
    return 0;
}