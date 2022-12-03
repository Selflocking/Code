#include <iostream>

using namespace std;

const int mxN = 2e5 + 10;

int n;
int arr[mxN];
int sum[mxN];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + arr[i];
        }
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            int bak = n - i - sum[n] + sum[i];
            if (arr[i]) { cnt += bak; }
        }
        int loc = 0;
        int add = 0;
        for (int i = 1; i <= n; ++i) {
            int pri = sum[i - 1];
            int bak = n - i - sum[n] + sum[i];
            if (arr[i]) {
                if (pri - bak > add) {
                    add = pri - bak;
                    loc = i;
                }
            } else {
                if (bak - pri > add) {
                    add = bak - pri;
                    loc = i;
                }
            }
        }
        cout << cnt + add << "\n";
    }

    return 0;
}