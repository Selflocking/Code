#include <algorithm>
#include <iostream>
using namespace std;
const int mxA = 1e9 + 5;
int n, m;
int arr[100005];

bool check(int x) {
    int sum = 1;
    int loc = arr[0];
    for (int i = 0; i < n; ++i) {
        if (arr[i] - loc >= x) {
            loc = arr[i];
            sum++;
        }
    }
    return m <= sum;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int lo = 1, hi = mxA;
    // lo~hi 距离，check牛的数量，距离越大，牛的数量越小。所以是单调递减。
    //需要找最大的距离。
    while (hi - lo > 1) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    //[lo, hi)
    cout << lo;
    return 0;
}