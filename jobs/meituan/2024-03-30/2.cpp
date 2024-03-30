#include <iostream>
#include <vector>

using namespace std;

constexpr int mxN = 2e5 + 5;
int main() {
    int n;
    vector<int> arr(mxN);
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    for (int i = 0; i < n; ++i) {
        int res = max(mx, 2 * arr[i]);
        cout << res << " ";
    }
    cout << "\n";
    return 0;
}
// 64 位输出请用 printf("%lld")