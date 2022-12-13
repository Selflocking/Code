#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
constexpr int mxN = 1e5 + 5;

int n;
int arr[mxN];
map<int, int> cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int res = 1;
    for (int l = 0, r = 0; r < n; ++r) {
        cnt[arr[r]]++;
        while (cnt[arr[r]] > 1) {
            cnt[arr[l]]--;
            l++;
        }
        res = max(res, r - l + 1);
    }
    cout << res;
    return 0;
}
