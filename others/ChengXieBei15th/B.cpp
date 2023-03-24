#include <bits/stdc++.h>

using namespace std;
;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }
    bool flag = sum % n == 0 ? true : false;
    int avg = sum / n;
    if (flag) {
        cout << n << "\n";
    } else {
        cout << n - 1 << "\n";
    }

    return 0;
}
