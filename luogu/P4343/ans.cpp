// https://www.luogu.com.cn/problem/P4343
#include <algorithm>
#include <iostream>

using namespace std;

int l, k;
int logs[100005];
bool flag = 0;
long long mi, ma;

int check(long long x) {
    int cnt = 0;
    long long sum = 0;
    for (int i = 0; i < l; ++i) {
        sum += logs[i];
        if (sum < 0) {
            sum = 0;
            continue;
        }
        if (sum >= x) {
            sum = 0;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    cin >> l >> k;
    for (int i = 0; i < l; ++i) {
        cin >> logs[i];
    }

    // min:
    long long lo = 1, ri = 1e14 + 5;
    while (lo <= ri) {
        long long mid = lo + (ri - lo) / 2;
        int res = check(mid);
        if (res < k) {
            ri = mid - 1;
        } else if (res > k) {
            lo = mid + 1;
        } else {
            ri = mid - 1;
            mi = mid;
            flag = 1;
        }
    }

    // max:
    lo = 1, ri = 1e14 + 5;
    while (lo <= ri) {
        long long mid = lo + (ri - lo) / 2;
        int res = check(mid);
        if (res < k) {
            ri = mid - 1;
        } else if (res > k) {
            lo = mid + 1;
        } else {
            lo = mid + 1;
            ma = mid;
            flag = 1;
        }
    }

    if (flag) {
        cout << mi << " " << ma;
    } else
        cout << -1;
    return 0;
}

// 1

// 1
// 1
// 1
// 1
// 1

// 1 5
// 2 2
// 3 1
// 4 1
// 5 1
// 6 0