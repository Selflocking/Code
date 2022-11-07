#include <iostream>
using namespace std;
const int mxN = 100005;

int arr[mxN];
int sum[mxN];
int main() {
    int n, m;
    cin >> n >> m;
    cin >> arr[1];
    sum[1] = arr[1];
    for (int i = 2; i <= n; i++) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << sum[b] - sum[a - 1] << "\n";
    }
    return 0;
}